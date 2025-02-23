#include "CreatureTimeIntervalEndAnimationAction.h"

CreatureTimeIntervalEndAnimationAction::CreatureTimeIntervalEndAnimationAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureTimeIntervalEndAnimationAction");
	Init();
}

CreatureTimeIntervalEndAnimationAction::~CreatureTimeIntervalEndAnimationAction()
{
}

void CreatureTimeIntervalEndAnimationAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("channel", Enums::GetChannel(Read(0x28)));
	AddSource("specialController", 0x2C);
	FORNOT("animations", 0x3C, 0x4)
	{
		m->AddText("Item", Enums::GetAnimation(m->Read(i)));
	}
	AddText("mode", Enums::GetAnimMode(Read(0x4C)));
}