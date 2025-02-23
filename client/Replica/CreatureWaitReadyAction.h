#pragma once
#include "../../Header.h"
class CreatureWaitReadyAction : public Module
{
public:
	CreatureWaitReadyAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureWaitReadyAction();

	void Init();
};