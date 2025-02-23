#pragma once
#include "../../Header.h"
class CreatureRunOnAllAction : public Module
{
public:
	CreatureRunOnAllAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureRunOnAllAction();

	void Init();
};