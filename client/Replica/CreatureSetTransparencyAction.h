#pragma once
#include "../../Header.h"
class CreatureSetTransparencyAction : public Module
{
public:
	CreatureSetTransparencyAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureSetTransparencyAction();

	void Init();
};