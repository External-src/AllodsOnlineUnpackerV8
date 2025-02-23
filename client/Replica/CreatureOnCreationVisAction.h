#pragma once
#include "../../Header.h"
class CreatureOnCreationVisAction : public Module
{
public:
	CreatureOnCreationVisAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureOnCreationVisAction();

	void Init();
};