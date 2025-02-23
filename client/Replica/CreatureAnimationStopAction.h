#pragma once
#include "../../Header.h"
class CreatureAnimationStopAction :
	public Module
{
public:
	CreatureAnimationStopAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureAnimationStopAction();

	void Init();
};

