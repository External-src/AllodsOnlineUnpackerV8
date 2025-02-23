#pragma once
#include "../../Header.h"
class CreatureAnimationFromCasterAction :
	public Module
{
public:
	CreatureAnimationFromCasterAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureAnimationFromCasterAction();

	void Init();
};

