#pragma once
#include "../../Header.h"
class DelayComponent :
	public Module
{
public:
	DelayComponent(DWORD struct_addr, string name, XDocument * d);
	~DelayComponent();

	void Init();
};

