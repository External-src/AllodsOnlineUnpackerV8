#pragma once
#include "../../Header.h"
class CreatureSayAction : public Module
{
public:
	CreatureSayAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureSayAction();

	void Init();
};