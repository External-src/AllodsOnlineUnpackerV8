#pragma once
#include "../../Header.h"
class SunShaftsComponent :
	public Module
{
public:
	SunShaftsComponent(DWORD struct_addr, string name, XDocument * d);
	~SunShaftsComponent();

	void Init();
};

