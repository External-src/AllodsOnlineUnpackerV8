#pragma once
#include "../../Header.h"
class CameraShakerComponent :
	public Module
{
public:
	CameraShakerComponent(DWORD struct_addr, string name, XDocument * d);
	~CameraShakerComponent();

	void Init();
};

