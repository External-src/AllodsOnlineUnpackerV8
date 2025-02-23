#pragma once
#include "../../Header.h"
class CreatureEffectsAction : public Module
{
public:
	CreatureEffectsAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureEffectsAction();

	void Init();
};