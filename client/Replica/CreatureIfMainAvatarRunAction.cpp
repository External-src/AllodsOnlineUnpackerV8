#include "CreatureIfMainAvatarRunAction.h"

CreatureIfMainAvatarRunAction::CreatureIfMainAvatarRunAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureIfMainAvatarRunAction");
	Init();
}

CreatureIfMainAvatarRunAction::~CreatureIfMainAvatarRunAction()
{
}

void CreatureIfMainAvatarRunAction::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("action", 0x24);
	AddText("checkCreature", Enums::GetCheckCreature(Read(0x28)));
}