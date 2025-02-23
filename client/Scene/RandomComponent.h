#pragma once
#include "../../Header.h"
class RandomComponent :
	public Module
{
public:
	RandomComponent(DWORD struct_addr, string name, XDocument * d);
	~RandomComponent();

	void Init();
};

