#pragma once
#include "../../Header.h"
class CreatureSheathAction : public Module
{
public:
	CreatureSheathAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureSheathAction();

	void Init();
};