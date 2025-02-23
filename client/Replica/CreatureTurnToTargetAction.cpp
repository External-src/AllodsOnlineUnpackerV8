#include "CreatureTurnToTargetAction.h"

CreatureTurnToTargetAction::CreatureTurnToTargetAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureTurnToTargetAction");
	Init();
}

CreatureTurnToTargetAction::~CreatureTurnToTargetAction()
{
}

void CreatureTurnToTargetAction::Init()
{
	AddSource("visActionID", 0x14);
	AddFloat("maxDistance", 0x24);
	AddFloat("minDistance", 0x28);
}