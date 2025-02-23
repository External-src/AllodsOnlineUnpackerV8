#include "VisPointLocator.h"

VisPointLocator::VisPointLocator(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.VisPointLocator");
	Init();
}

VisPointLocator::~VisPointLocator()
{
}

void VisPointLocator::Init()
{
	AddText("from", Enums::GetFrom(Read(0x24)));
	AddText("locator", Enums::GetLocatorSlot(Read(0x28)));
	AddSource("locatorName", 0x2C);
	AddText("member", Enums::GetMember(Read(0x38)));
}