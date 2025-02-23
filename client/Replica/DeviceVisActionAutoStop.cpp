#include "DeviceVisActionAutoStop.h"

DeviceVisActionAutoStop::DeviceVisActionAutoStop(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceVisActionAutoStop");
	Init();
}

DeviceVisActionAutoStop::~DeviceVisActionAutoStop()
{
}

void DeviceVisActionAutoStop::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("action", 0x28);
}