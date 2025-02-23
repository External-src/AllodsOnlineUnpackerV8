#pragma once
#include "../../Header.h"
class CreatureOnParameterChangedAction : public Module
{
public:
	CreatureOnParameterChangedAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureOnParameterChangedAction();

	void Init();
};