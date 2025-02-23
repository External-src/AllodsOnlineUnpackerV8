#pragma once
#include "../../Header.h"
class CreatureItemAnimationAction : public Module
{
public:
	CreatureItemAnimationAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureItemAnimationAction();

	void Init();
};