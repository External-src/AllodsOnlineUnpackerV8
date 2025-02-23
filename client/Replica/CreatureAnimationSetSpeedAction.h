#pragma once
#include "../../Header.h"
class CreatureAnimationSetSpeedAction :
	public Module
{
public:
	CreatureAnimationSetSpeedAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureAnimationSetSpeedAction();

	void Init();
};

