#include "EntityVisActionIfVisObject.h"

EntityVisActionIfVisObject::EntityVisActionIfVisObject(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.EntityVisActionIfVisObject");
	Init();
}

EntityVisActionIfVisObject::~EntityVisActionIfVisObject()
{
}

void EntityVisActionIfVisObject::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("defaultVisAction", 0x28);
	FORCON("visObjectMatches", 0x2C, 0x10)
	{
		m->OpenCon("visAction", 0x4);
		m->AddHref("visObject", 0x8);
	}
}