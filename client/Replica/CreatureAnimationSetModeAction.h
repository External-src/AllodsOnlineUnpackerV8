#pragma once
#include "../../Header.h"
class CreatureAnimationSetModeAction :
	public Module
{
public:
	CreatureAnimationSetModeAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureAnimationSetModeAction();

	void Init();
};

