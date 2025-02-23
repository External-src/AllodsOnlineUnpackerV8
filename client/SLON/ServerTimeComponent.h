#pragma once
#include "../../Header.h"
class ServerTimeComponent :
	public Module
{
public:
	ServerTimeComponent(DWORD struct_addr, string name, XDocument * d);
	~ServerTimeComponent();

	void Init();
};

