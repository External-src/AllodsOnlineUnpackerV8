#pragma once
#include "../../Header.h"
class CreatureUseIntervalsVisAction : public Module
{
public:
	CreatureUseIntervalsVisAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureUseIntervalsVisAction();

	void Init();
};