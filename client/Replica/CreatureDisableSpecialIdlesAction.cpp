#include "CreatureDisableSpecialIdlesAction.h"

CreatureDisableSpecialIdlesAction::CreatureDisableSpecialIdlesAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureDisableSpecialIdlesAction");
	Init();
}

CreatureDisableSpecialIdlesAction::~CreatureDisableSpecialIdlesAction()
{
}

void CreatureDisableSpecialIdlesAction::Init()
{
	AddSource("visActionID", 0x14);
}