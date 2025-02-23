#include "CreatureMusicParamAction.h"

CreatureMusicParamAction::CreatureMusicParamAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureMusicParamAction");
	Init();
}

CreatureMusicParamAction::~CreatureMusicParamAction()
{
}

void CreatureMusicParamAction::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("creatureParameter", 0x24);
	AddText("fromCreature", Enums::GetFromCreature(Read(0x28)));
	AddHref("parameter", 0x2C);
	AddFloat("value", 0x34);
}