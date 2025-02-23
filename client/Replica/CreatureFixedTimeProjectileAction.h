#pragma once
#include "../../Header.h"
class CreatureFixedTimeProjectileAction : public Module
{
public:
	CreatureFixedTimeProjectileAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureFixedTimeProjectileAction();

	void Init();
};