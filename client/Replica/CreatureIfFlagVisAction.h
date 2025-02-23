#pragma once
#include "../../Header.h"
class CreatureIfFlagVisAction : public Module
{
public:
	CreatureIfFlagVisAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureIfFlagVisAction();

	void Init();
};