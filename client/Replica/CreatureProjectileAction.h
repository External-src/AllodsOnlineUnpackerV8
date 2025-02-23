#pragma once
#include "../../Header.h"
class CreatureProjectileAction : public Module
{
public:
	CreatureProjectileAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureProjectileAction();

	void Init();
};