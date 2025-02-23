#pragma once
#include "../../Header.h"
class CustomIdleComponent :
	public Module
{
public:
	CustomIdleComponent(DWORD struct_addr, string name, XDocument * d);
	~CustomIdleComponent();

	void Init();
};

