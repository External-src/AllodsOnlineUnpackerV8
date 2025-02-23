#include "DeviceVisActionList.h"

DeviceVisActionList::DeviceVisActionList(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceVisActionList");
	Init();
}

DeviceVisActionList::~DeviceVisActionList()
{
}

void DeviceVisActionList::Init()
{
	AddSource("visActionID", 0x14);
	FORTYPE("elements", 0x28, 0x4);
	AddText("play", Enums::GetPlay(Read(0x38)));
}