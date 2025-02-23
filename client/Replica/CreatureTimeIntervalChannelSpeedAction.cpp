#include "CreatureTimeIntervalChannelSpeedAction.h"

CreatureTimeIntervalChannelSpeedAction::CreatureTimeIntervalChannelSpeedAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureTimeIntervalChannelSpeedAction");
	Init();
}

CreatureTimeIntervalChannelSpeedAction::~CreatureTimeIntervalChannelSpeedAction()
{
}

void CreatureTimeIntervalChannelSpeedAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("channel", Enums::GetChannel(Read(0x28)));
	AddSource("specialController", 0x2C);
	AddFloat("endSpeed", 0x3C);
	AddInt("endTime", 0x40);
	AddFloat("frozenSpeed", 0x44);
	AddFloat("startSpeed", 0x48);
}