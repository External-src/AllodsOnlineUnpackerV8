#pragma once
#include "../../Header.h"
class LightMutatorComponent :
	public Module
{
public:
	LightMutatorComponent(DWORD struct_addr, string name, XDocument * d);
	~LightMutatorComponent();

	void Init();
};

