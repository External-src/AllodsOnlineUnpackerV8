#include "DeviceVisActionChangeModel.h"

DeviceVisActionChangeModel::DeviceVisActionChangeModel(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceVisActionChangeModel");
	Init();
}

DeviceVisActionChangeModel::~DeviceVisActionChangeModel()
{
}

void DeviceVisActionChangeModel::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("collision", 0x28);
	AddFloat("priority", 0x30);
	AddHref("visObj", 0x34);
}