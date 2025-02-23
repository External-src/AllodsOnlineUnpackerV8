#pragma once
#include "../../Header.h"
class DayTimeComponent :
	public Module
{
public:
	DayTimeComponent(DWORD struct_addr, string name, XDocument * d);
	~DayTimeComponent();

	void Init();
};

