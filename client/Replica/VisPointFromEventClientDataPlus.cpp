#include "VisPointFromEventClientDataPlus.h"

VisPointFromEventClientDataPlus::VisPointFromEventClientDataPlus(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.VisPointFromEventClientDataPlus");
	Init();
}

VisPointFromEventClientDataPlus::~VisPointFromEventClientDataPlus()
{
}

void VisPointFromEventClientDataPlus::Init()
{
	AddVector3("shift", 0x14);
	AddInt("index", 0x24);
	AddSource("locatorName", 0x28);
	AddBool("fromTarget", 0x34);
}