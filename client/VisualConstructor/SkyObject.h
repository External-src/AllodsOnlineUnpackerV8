#pragma once
#include "../../Header.h"
class SkyObject :
	public Module
{
public:
	SkyObject(DWORD struct_addr, string name, XDocument * d);
	~SkyObject();

	void Init();
};

