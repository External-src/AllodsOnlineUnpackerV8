#include "CreatureSwitchDistToTargetAction.h"

CreatureSwitchDistToTargetAction::CreatureSwitchDistToTargetAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureSwitchDistToTargetAction");
	Init();
}

CreatureSwitchDistToTargetAction::~CreatureSwitchDistToTargetAction()
{
}

void CreatureSwitchDistToTargetAction::Init()
{
	AddSource("visActionID", 0x14);
	FORCON("cases", 0x24, 0x0C)
	{
		m->OpenCon("action", 0x4);
		m->AddFloat("maxDist", 0x8);
	}
}