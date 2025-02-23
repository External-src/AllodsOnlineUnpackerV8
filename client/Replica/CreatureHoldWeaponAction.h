#pragma once
#include "../../Header.h"
class CreatureHoldWeaponAction : public Module
{
public:
	CreatureHoldWeaponAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureHoldWeaponAction();

	void Init();
};