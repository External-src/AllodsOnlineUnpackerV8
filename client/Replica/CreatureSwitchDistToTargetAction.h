#pragma once
#include "../../Header.h"
class CreatureSwitchDistToTargetAction : public Module
{
public:
	CreatureSwitchDistToTargetAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureSwitchDistToTargetAction();

	void Init();
};