#pragma once
#include "../../Header.h"
class CreatureSetAnimationPropertiesAction : public Module
{
public:
	CreatureSetAnimationPropertiesAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureSetAnimationPropertiesAction();

	void Init();
};