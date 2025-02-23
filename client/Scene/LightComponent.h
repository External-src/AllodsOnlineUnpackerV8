#pragma once
#include "../../Header.h"
class LightComponent :
	public Module
{
public:
	LightComponent(DWORD struct_addr, string name, XDocument * d);
	~LightComponent();

	void Init();
};

