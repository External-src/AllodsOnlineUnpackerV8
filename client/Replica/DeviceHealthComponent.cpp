#include "DeviceHealthComponent.h"

DeviceHealthComponent::DeviceHealthComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceHealthComponent");
	Init();
}

DeviceHealthComponent::~DeviceHealthComponent()
{
}

void DeviceHealthComponent::Init()
{
	FORCON("states", 0x18, 0x0C)
	{
		m->AddFloat("health", 0x4);
		m->OpenCon("script", 0x8);
	}
	AddBool("useParentState", 0x28);
}