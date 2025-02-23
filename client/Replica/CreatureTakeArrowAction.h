#pragma once
#include "../../Header.h"
class CreatureTakeArrowAction : public Module
{
public:
	CreatureTakeArrowAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureTakeArrowAction();

	void Init();
};