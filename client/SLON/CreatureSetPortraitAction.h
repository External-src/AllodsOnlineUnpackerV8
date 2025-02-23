#pragma once
#include "../../Header.h"
class CreatureSetPortraitAction : public Module
{
public:
	CreatureSetPortraitAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureSetPortraitAction();

	void Init();
};