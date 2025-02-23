#include "VisActionRefCounter.h"

VisActionRefCounter::VisActionRefCounter(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.VisActionRefCounter");
	Init();
}

VisActionRefCounter::~VisActionRefCounter()
{
}

void VisActionRefCounter::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("action", 0x24);
	AddSource("keyWord", 0x28);
}