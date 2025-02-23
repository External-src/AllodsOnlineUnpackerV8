#pragma once
#include "../../Header.h"
class CreaturePetVisAction : public Module
{
public:
	CreaturePetVisAction(DWORD struct_addr, string name, XDocument * d);
	~CreaturePetVisAction();

	void Init();
};