#include "CreatureVisActionStartThrow.h"

CreatureVisActionStartThrow::CreatureVisActionStartThrow(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureVisActionStartThrow");
	Init();
}

CreatureVisActionStartThrow::~CreatureVisActionStartThrow()
{
}

void CreatureVisActionStartThrow::Init()
{
	AddSource("visActionID", 0x14);
}