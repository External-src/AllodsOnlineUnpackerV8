#pragma once
#include "../../Header.h"
class CreatureSetSwimHeightAction : public Module
{
public:
	CreatureSetSwimHeightAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureSetSwimHeightAction();

	void Init();
};