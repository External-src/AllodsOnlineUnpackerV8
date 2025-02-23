#pragma once
#include "../../Header.h"
class CreatureGridViewAction : public Module
{
public:
	CreatureGridViewAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureGridViewAction();

	void Init();
};