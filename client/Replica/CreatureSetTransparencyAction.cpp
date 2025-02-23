#include "CreatureSetTransparencyAction.h"

CreatureSetTransparencyAction::CreatureSetTransparencyAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureSetTransparencyAction");
	Init();
}

CreatureSetTransparencyAction::~CreatureSetTransparencyAction()
{
}

void CreatureSetTransparencyAction::Init()
{
	AddSource("visActionID", 0x14);
	AddFloat("fadeMult", 0x24);
	AddInt("priority", 0x28);
	AddFloat("transparency", 0x2C);
}