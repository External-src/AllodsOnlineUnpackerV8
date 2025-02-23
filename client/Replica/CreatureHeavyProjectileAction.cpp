#include "CreatureHeavyProjectileAction.h"

CreatureHeavyProjectileAction::CreatureHeavyProjectileAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureHeavyProjectileAction");
	Init();
}

CreatureHeavyProjectileAction::~CreatureHeavyProjectileAction()
{
}

void CreatureHeavyProjectileAction::Init()
{
	AddSource("visActionID", 0x14);
	AddSource("fromLocator", 0x24);
	AddHref("hullCrit", 0x30);
	AddHref("hullExplosion", 0x38);
	AddHref("projectileFx", 0x40);
	AddHref("shieldCrit", 0x48);
	AddHref("shieldExplosion", 0x50);
}