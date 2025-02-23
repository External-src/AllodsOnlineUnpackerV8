#pragma once
#include "../../Header.h"
class CreatureAnimationAction :
	public Module
{
public:
	CreatureAnimationAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureAnimationAction();

	void Init();
};

