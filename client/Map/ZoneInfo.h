#pragma once
#include "../../Header.h"
class ZoneInfo :
	public Module
{
public:
	ZoneInfo(DWORD struct_addr, string name, XDocument * d);
	~ZoneInfo();

	void Init();
};

