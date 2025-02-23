#pragma once
#include "../../Header.h"
class HealthParameter : public Module
{
public:
	HealthParameter(DWORD struct_addr, string name, XDocument * d);
	~HealthParameter();

	void Init();
};