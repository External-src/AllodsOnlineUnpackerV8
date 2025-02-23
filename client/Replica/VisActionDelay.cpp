#include "VisActionDelay.h"

VisActionDelay::VisActionDelay(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.VisActionDelay");
	Init();
}

VisActionDelay::~VisActionDelay()
{
}

void VisActionDelay::Init()
{
	AddSource("visActionID", 0x14);
	AddInt("time", 0x24);
}