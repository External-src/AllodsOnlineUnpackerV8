#include "DeviceFixedPointProjectileAction.h"

DeviceFixedPointProjectileAction::DeviceFixedPointProjectileAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceFixedPointProjectileAction");
	Init();
}

DeviceFixedPointProjectileAction::~DeviceFixedPointProjectileAction()
{
}

void DeviceFixedPointProjectileAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("explosionFx", 0x28);
	FORCON("lines", 0x30, 0x10)
	{
		m->AddInt("endPointIndex", 0x4);
		m->AddInt("startPointIndex", 0x8);
		m->AddInt("throwDuration", 0x0C);
	}
	AddHref("projectileFx", 0x40);
	AddFloat("theGe", 0x48);
}