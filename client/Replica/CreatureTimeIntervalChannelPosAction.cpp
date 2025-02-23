#include "CreatureTimeIntervalChannelPosAction.h"

CreatureTimeIntervalChannelPosAction::CreatureTimeIntervalChannelPosAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureTimeIntervalChannelPosAction");
	Init();
}

CreatureTimeIntervalChannelPosAction::~CreatureTimeIntervalChannelPosAction()
{
}

void CreatureTimeIntervalChannelPosAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("channel", Enums::GetChannel(Read(0x28)));
	AddSource("specialController", 0x2C);
}