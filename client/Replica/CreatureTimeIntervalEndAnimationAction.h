#pragma once
#include "../../Header.h"
class CreatureTimeIntervalEndAnimationAction : public Module
{
public:
	CreatureTimeIntervalEndAnimationAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureTimeIntervalEndAnimationAction();

	void Init();
};