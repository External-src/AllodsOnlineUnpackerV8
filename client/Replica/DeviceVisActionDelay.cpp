#include "DeviceVisActionDelay.h"

DeviceVisActionDelay::DeviceVisActionDelay(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceVisActionDelay");
	Init();
}

DeviceVisActionDelay::~DeviceVisActionDelay()
{
}

void DeviceVisActionDelay::Init()
{
	AddSource("visActionID", 0x14);
	AddInt("time", 0x28);
}