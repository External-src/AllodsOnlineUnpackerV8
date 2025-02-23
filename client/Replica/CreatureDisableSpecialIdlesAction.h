#pragma once
#include "../../Header.h"
class CreatureDisableSpecialIdlesAction : public Module
{
public:
	CreatureDisableSpecialIdlesAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureDisableSpecialIdlesAction();

	void Init();
};