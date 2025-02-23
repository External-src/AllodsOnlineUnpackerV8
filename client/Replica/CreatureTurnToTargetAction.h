#pragma once
#include "../../Header.h"
class CreatureTurnToTargetAction : public Module
{
public:
	CreatureTurnToTargetAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureTurnToTargetAction();

	void Init();
};