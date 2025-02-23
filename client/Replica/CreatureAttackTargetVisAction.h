#pragma once
#include "../../Header.h"
class CreatureAttackTargetVisAction : public Module
{
public:
	CreatureAttackTargetVisAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureAttackTargetVisAction();

	void Init();
};