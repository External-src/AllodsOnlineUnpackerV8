#pragma once
#include "../../Header.h"
class CreatureDisableHitsAction : public Module
{
public:
	CreatureDisableHitsAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureDisableHitsAction();

	void Init();
};