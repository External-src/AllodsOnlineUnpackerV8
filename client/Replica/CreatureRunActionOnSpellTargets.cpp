#include "CreatureRunActionOnSpellTargets.h"

CreatureRunActionOnSpellTargets::CreatureRunActionOnSpellTargets(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureRunActionOnSpellTargets");
	Init();
}

CreatureRunActionOnSpellTargets::~CreatureRunActionOnSpellTargets()
{
}

void CreatureRunActionOnSpellTargets::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("targetAction", 0x24);
}