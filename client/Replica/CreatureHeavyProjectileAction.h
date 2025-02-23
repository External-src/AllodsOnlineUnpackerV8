#pragma once
#include "../../Header.h"
class CreatureHeavyProjectileAction : public Module
{
public:
	CreatureHeavyProjectileAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureHeavyProjectileAction();

	void Init();
};