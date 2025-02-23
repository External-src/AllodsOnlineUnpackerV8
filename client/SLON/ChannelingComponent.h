#pragma once
#include "../../Header.h"
class ChannelingComponent :
	public Module
{
public:
	ChannelingComponent(DWORD struct_addr, string name, XDocument * d);
	~ChannelingComponent();

	void Init();
};

