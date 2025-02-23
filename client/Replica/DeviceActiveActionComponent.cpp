#include "DeviceActiveActionComponent.h"

DeviceActiveActionComponent::DeviceActiveActionComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceActiveActionComponent");
	Init();
}

DeviceActiveActionComponent::~DeviceActiveActionComponent()
{
}

void DeviceActiveActionComponent::Init()
{
	FORCON("scripts", 0x18, 0x1C)
	{
		m->AddHref("fromAction", 0x4);
		m->OpenCon("script", 0x0C);
		m->AddHref("toAction", 0x10);
		m->AddBool("fromAny", 0x18);
	}
}