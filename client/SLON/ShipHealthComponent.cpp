#include "ShipHealthComponent.h"

ShipHealthComponent::ShipHealthComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.ShipHealthComponent");
	Init();
}

ShipHealthComponent::~ShipHealthComponent()
{
}

void ShipHealthComponent::Init()
{
	FORCON("states", 0x18, 0x0C)
	{
		m->AddFloat("health", 0x4);
		m->OpenCon("script", 0x8);
	}
}