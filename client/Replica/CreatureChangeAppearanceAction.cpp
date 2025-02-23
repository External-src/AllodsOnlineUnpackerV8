#include "CreatureChangeAppearanceAction.h"

CreatureChangeAppearanceAction::CreatureChangeAppearanceAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureChangeAppearanceAction");
	Init();
}

CreatureChangeAppearanceAction::~CreatureChangeAppearanceAction()
{
}

void CreatureChangeAppearanceAction::Init()
{
	AddSource("visActionID", 0x14);
}