#pragma once
#include "../../Header.h"
class CreatureLockTargetAction : public Module
{
public:
	CreatureLockTargetAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureLockTargetAction();

	void Init();
};