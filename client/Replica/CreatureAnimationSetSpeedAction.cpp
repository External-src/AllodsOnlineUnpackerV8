#include "CreatureAnimationSetSpeedAction.h"

CreatureAnimationSetSpeedAction::CreatureAnimationSetSpeedAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureAnimationSetSpeedAction");
	Init();
}

CreatureAnimationSetSpeedAction::~CreatureAnimationSetSpeedAction()
{
}

void CreatureAnimationSetSpeedAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("channel", Enums::GetChannel(Read(0x24)));
	AddSource("specialController", 0x28);
	AddFloat("speed", 0x34);
}
