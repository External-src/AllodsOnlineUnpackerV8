#include "CreatureSetSwimHeightAction.h"

CreatureSetSwimHeightAction::CreatureSetSwimHeightAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureSetSwimHeightAction");
	Init();
}

CreatureSetSwimHeightAction::~CreatureSetSwimHeightAction()
{
}

void CreatureSetSwimHeightAction::Init()
{
	AddSource("visActionID", 0x14);
	AddFloat("swimHeight", 0x24);
}