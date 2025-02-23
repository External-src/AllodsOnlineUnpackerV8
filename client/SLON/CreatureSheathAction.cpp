#include "CreatureSheathAction.h"

CreatureSheathAction::CreatureSheathAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureSheathAction");
	Init();
}

CreatureSheathAction::~CreatureSheathAction()
{
}

void CreatureSheathAction::Init()
{
	AddSource("visActionID", 0x14);
}