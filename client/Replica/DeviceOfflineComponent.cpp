#include "DeviceOfflineComponent.h"

DeviceOfflineComponent::DeviceOfflineComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceOfflineComponent");
	Init();
}

DeviceOfflineComponent::~DeviceOfflineComponent()
{
}

void DeviceOfflineComponent::Init()
{
	OpenCon("malfunctionScript", 0x18);
	OpenCon("offlineScript", 0x1C);
	OpenCon("onlineScript", 0x20);
	OpenCon("overheatScript", 0x24);
}