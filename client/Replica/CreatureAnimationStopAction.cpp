#include "CreatureAnimationStopAction.h"

CreatureAnimationStopAction::CreatureAnimationStopAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureAnimationStopAction");
	Init();
}

CreatureAnimationStopAction::~CreatureAnimationStopAction()
{
}

void CreatureAnimationStopAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("channel", Enums::GetChannel(Read(0x24)));
	AddSource("specialController", 0x28);
}
