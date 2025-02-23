#pragma once
#include "../../Header.h"
class TrailComponent :
	public Module
{
public:
	TrailComponent(DWORD struct_addr, string name, XDocument * d);
	~TrailComponent();

	void Init();
};

