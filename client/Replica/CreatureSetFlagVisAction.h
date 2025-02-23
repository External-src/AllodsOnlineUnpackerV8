#pragma once
#include "../../Header.h"
class CreatureSetFlagVisAction : public Module
{
public:
	CreatureSetFlagVisAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureSetFlagVisAction();

	void Init();
};