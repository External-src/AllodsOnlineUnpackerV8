#pragma once
#include "../../Header.h"
class CreatureShowHaloAction : public Module
{
public:
	CreatureShowHaloAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureShowHaloAction();

	void Init();
};