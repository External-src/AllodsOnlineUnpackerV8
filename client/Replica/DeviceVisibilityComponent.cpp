#include "DeviceVisibilityComponent.h"

DeviceVisibilityComponent::DeviceVisibilityComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceVisibilityComponent");
	Init();
}

DeviceVisibilityComponent::~DeviceVisibilityComponent()
{
}

void DeviceVisibilityComponent::Init()
{
	AddInt("actionID", 0x18);
}