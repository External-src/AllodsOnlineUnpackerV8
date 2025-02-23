#include "CreatureDisableHitsAction.h"

CreatureDisableHitsAction::CreatureDisableHitsAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureDisableHitsAction");
	Init();
}

CreatureDisableHitsAction::~CreatureDisableHitsAction()
{
}

void CreatureDisableHitsAction::Init()
{
	AddSource("visActionID", 0x14);
	AddBool("disableCrits", 0x24);
	AddBool("disableHits", 0x25);
}