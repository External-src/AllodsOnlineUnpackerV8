#include "CreatureEnchantWeaponAction.h"

CreatureEnchantWeaponAction::CreatureEnchantWeaponAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureEnchantWeaponAction");
	Init();
}

CreatureEnchantWeaponAction::~CreatureEnchantWeaponAction()
{
}

void CreatureEnchantWeaponAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("enchant", 0x24);
	AddText("whatToEnchant", Enums::GetWTE(Read(0x2C)));
}