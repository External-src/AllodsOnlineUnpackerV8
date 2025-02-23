#pragma once
#include "../../Header.h"
class CreatureVisActionOnSelectableTargets : public Module
{
public:
	CreatureVisActionOnSelectableTargets(DWORD struct_addr, string name, XDocument * d);
	~CreatureVisActionOnSelectableTargets();

	void Init();
};