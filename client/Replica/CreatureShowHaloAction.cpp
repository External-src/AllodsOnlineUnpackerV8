#include "CreatureShowHaloAction.h"

CreatureShowHaloAction::CreatureShowHaloAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureShowHaloAction");
	Init();
}

CreatureShowHaloAction::~CreatureShowHaloAction()
{
}

void CreatureShowHaloAction::Init()
{
	AddSource("visActionID", 0x14);
	AddBool("show", 0x24);
	AddBool("topPriority", 0x25);
}