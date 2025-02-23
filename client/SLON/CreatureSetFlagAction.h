#pragma once
#include "../../Header.h"
class CreatureSetFlagAction : public Module
{
public:
	CreatureSetFlagAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureSetFlagAction();

	void Init();
};