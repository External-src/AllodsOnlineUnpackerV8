#include "DamageDecalManager.h"

DamageDecalManager::DamageDecalManager(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.DamageDecalManager");
	Init();
}

DamageDecalManager::~DamageDecalManager()
{
}

void DamageDecalManager::Init()
{
	FORNOT("damageDecals", 0x18, 0x0C)
	{
		m->AddSource("Item", i);
	}
}