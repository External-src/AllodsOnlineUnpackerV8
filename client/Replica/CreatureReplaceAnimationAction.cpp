#include "CreatureReplaceAnimationAction.h"

CreatureReplaceAnimationAction::CreatureReplaceAnimationAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureReplaceAnimationAction");
	Init();
}

CreatureReplaceAnimationAction::~CreatureReplaceAnimationAction()
{
}

void CreatureReplaceAnimationAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("action", Enums::GetVisAction(Read(0x24)));
	AddText("newAnimation", Enums::GetAnimation(Read(0x28)));
}