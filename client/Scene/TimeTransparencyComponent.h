#pragma once
#include "../../Header.h"
class TimeTransparencyComponent :
	public Module
{
public:
	TimeTransparencyComponent(DWORD struct_addr, string name, XDocument * d);
	~TimeTransparencyComponent();

	void Init();
};

