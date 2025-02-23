#pragma once
#include "../../Header.h"
class CreatureTakeBowStringAction : public Module
{
public:
	CreatureTakeBowStringAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureTakeBowStringAction();

	void Init();
};