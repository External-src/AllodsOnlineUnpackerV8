#include "CreatureVisActionOnSelectableTargets.h"

CreatureVisActionOnSelectableTargets::CreatureVisActionOnSelectableTargets(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureVisActionOnSelectableTargets");
	Init();
}

CreatureVisActionOnSelectableTargets::~CreatureVisActionOnSelectableTargets()
{
}

void CreatureVisActionOnSelectableTargets::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("playOnNotSelectable", 0x24);
	OpenCon("playOnSelectable", 0x28);
}