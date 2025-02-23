#include "ShipEngineComponent.h"

ShipEngineComponent::ShipEngineComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.ShipEngineComponent");
	Init();
}

ShipEngineComponent::~ShipEngineComponent()
{
}

void ShipEngineComponent::Init()
{
	FORCON("angularVelocityScripts", 0x18, 0x0C)
	{
		m->OpenCon("script", 0x4);
		m->AddFloat("speedValue", 0x8);
	}
	AddSFX("engineSound", 0x28);
	OpenCon("inHangarScript", 0x44);
	OpenCon("onIslandScript", 0x48);
	FORCON("velocityScripts", 0x4C, 0x0C)
	{
		m->OpenCon("script", 0x4);
		m->AddFloat("speedValue", 0x8);
	}
	AddBool("useTargetSpeed", 0x5C);
}