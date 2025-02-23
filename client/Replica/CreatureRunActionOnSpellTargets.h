#pragma once
#include "../../Header.h"
class CreatureRunActionOnSpellTargets : public Module
{
public:
	CreatureRunActionOnSpellTargets(DWORD struct_addr, string name, XDocument * d);
	~CreatureRunActionOnSpellTargets();

	void Init();
};