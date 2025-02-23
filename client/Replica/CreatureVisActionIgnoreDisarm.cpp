#include "CreatureVisActionIgnoreDisarm.h"

CreatureVisActionIgnoreDisarm::CreatureVisActionIgnoreDisarm(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureVisActionIgnoreDisarm");
	Init();
}

CreatureVisActionIgnoreDisarm::~CreatureVisActionIgnoreDisarm()
{
}

void CreatureVisActionIgnoreDisarm::Init()
{
	AddSource("visActionID", 0x14);
}