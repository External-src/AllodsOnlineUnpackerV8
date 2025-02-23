#pragma once
#include "../../Header.h"
class StopVisObjectComponents :
	public Module
{
public:
	StopVisObjectComponents(DWORD struct_addr, string name, XDocument * d);
	~StopVisObjectComponents();

	void Init();
};

