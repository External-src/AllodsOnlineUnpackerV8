#pragma once
#include "../../Header.h"
class CreatureThrowArrowAction : public Module
{
public:
	CreatureThrowArrowAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureThrowArrowAction();

	void Init();
};