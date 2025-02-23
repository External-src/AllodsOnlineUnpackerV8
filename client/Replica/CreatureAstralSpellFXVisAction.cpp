#include "CreatureAstralSpellFXVisAction.h"

CreatureAstralSpellFXVisAction::CreatureAstralSpellFXVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureAstralSpellFXVisAction");
	Init();
}

CreatureAstralSpellFXVisAction::~CreatureAstralSpellFXVisAction()
{
}

void CreatureAstralSpellFXVisAction::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("astralSpell", 0x24);
}
