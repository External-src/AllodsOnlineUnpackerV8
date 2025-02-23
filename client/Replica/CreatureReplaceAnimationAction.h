#pragma once
#include "../../Header.h"
class CreatureReplaceAnimationAction : public Module
{
public:
	CreatureReplaceAnimationAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureReplaceAnimationAction();

	void Init();
};