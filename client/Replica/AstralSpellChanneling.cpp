#include "AstralSpellChanneling.h"

AstralSpellChanneling::AstralSpellChanneling(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.AstralSpellChanneling");
	Init();
}

AstralSpellChanneling::~AstralSpellChanneling()
{
}

void AstralSpellChanneling::Init()
{
	AddFloat("fxLength", 0x18);
	AddHref("hullExplosion", 0x1C);
	AddSource("locatorName", 0x24);
	AddSource("locatorTo", 0x30);
	AddHref("projectileFx", 0x3C);
	AddHref("shieldExplosion", 0x44);
	AddText("targetSettings", Enums::GetTargetSettings(Read(0x4C)));
	AddBool("ignoreShield", 0x50);
}
