#pragma once
#include "../../Header.h"
class CreatureEnchantWeaponAction : public Module
{
public:
	CreatureEnchantWeaponAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureEnchantWeaponAction();

	void Init();
};