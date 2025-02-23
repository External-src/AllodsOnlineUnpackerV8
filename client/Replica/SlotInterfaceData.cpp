#include "SlotInterfaceData.h"

SlotInterfaceData::SlotInterfaceData(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.SlotInterfaceData");
	Init();
}

SlotInterfaceData::~SlotInterfaceData()
{
}

void SlotInterfaceData::Init()
{
	AddInt("interfaceSlot", 0x18);
}