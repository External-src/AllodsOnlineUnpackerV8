#include "SlotLink.h"

SlotLink::SlotLink(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.SlotLink");
	Init();
}

SlotLink::~SlotLink()
{
}

void SlotLink::Init()
{
	AddSource("locatorName", 0x18);
}