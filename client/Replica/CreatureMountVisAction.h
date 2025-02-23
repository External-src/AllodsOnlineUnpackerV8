#pragma once
#include "../../Header.h"
class CreatureMountVisAction : public Module
{
public:
	CreatureMountVisAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureMountVisAction();

	void Init();
};