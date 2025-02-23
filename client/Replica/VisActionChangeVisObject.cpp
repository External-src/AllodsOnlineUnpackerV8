#include "VisActionChangeVisObject.h"

VisActionChangeVisObject::VisActionChangeVisObject(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.VisActionChangeVisObject");
	Init();
}

VisActionChangeVisObject::~VisActionChangeVisObject()
{
}

void VisActionChangeVisObject::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("newVisMob", 0x24);
	AddBool("getBody", 0x2C);
	AddBool("getDress", 0x2D);
}