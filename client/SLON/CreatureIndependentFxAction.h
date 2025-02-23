#pragma once
#include "../../Header.h"
class CreatureIndependentFxAction : public Module
{
public:
	CreatureIndependentFxAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureIndependentFxAction();

	void Init();
};