#pragma once
#include "../../Header.h"
class CreatureHideMountVisAction : public Module
{
public:
	CreatureHideMountVisAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureHideMountVisAction();

	void Init();
};