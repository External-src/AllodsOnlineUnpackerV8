#pragma once
#include "../../Header.h"
class DayTimeParameter : public Module
{
public:
	DayTimeParameter(DWORD struct_addr, string name, XDocument * d);
	~DayTimeParameter();

	void Init();
};