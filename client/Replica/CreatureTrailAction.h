#pragma once
#include "../../Header.h"
class CreatureTrailAction : public Module
{
public:
	CreatureTrailAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureTrailAction();

	void Init();
};