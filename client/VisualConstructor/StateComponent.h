#pragma once
#include "../../Header.h"
class StateComponent :
	public Module
{
public:
	StateComponent(DWORD struct_addr, string name, XDocument * d);
	~StateComponent();

	void Init();
};

