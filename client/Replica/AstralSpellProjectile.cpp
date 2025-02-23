#include "AstralSpellProjectile.h"

AstralSpellProjectile::AstralSpellProjectile(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.AstralSpellProjectile");
	Init();
}

AstralSpellProjectile::~AstralSpellProjectile()
{
}

void AstralSpellProjectile::Init()
{
	AddHref("hullCrit", 0x18);
	AddHref("hullExplosion", 0x20);
	AddSource("locatorName", 0x28);
	AddSource("locatorTo", 0x34);
	AddHref("projectileFx", 0x40);
	AddHref("shieldCrit", 0x48);
	AddHref("shieldExplosion", 0x50);
}