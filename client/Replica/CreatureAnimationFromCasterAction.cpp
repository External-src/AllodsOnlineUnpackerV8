#include "CreatureAnimationFromCasterAction.h"

CreatureAnimationFromCasterAction::CreatureAnimationFromCasterAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureAnimationFromCasterAction");
	Init();
}

CreatureAnimationFromCasterAction::~CreatureAnimationFromCasterAction()
{
}

void CreatureAnimationFromCasterAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("channel", Enums::GetChannel(Read(0x24)));
	AddSource("specialController", 0x28);
}
