#pragma once
#include "../../Header.h"
class CreatureFixedPointProjectileAction : public Module
{
public:
	CreatureFixedPointProjectileAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureFixedPointProjectileAction();

	void Init();
};