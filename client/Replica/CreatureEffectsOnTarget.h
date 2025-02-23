#pragma once
#include "../../Header.h"
class CreatureEffectsOnTarget : public Module
{
public:
	CreatureEffectsOnTarget(DWORD struct_addr, string name, XDocument * d);
	~CreatureEffectsOnTarget();

	void Init();
};