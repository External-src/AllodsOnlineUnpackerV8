#pragma once
#include "../../Header.h"
class ShipBuildStatus : public Module
{
public:
	ShipBuildStatus(DWORD struct_addr, string name, XDocument * d);
	~ShipBuildStatus();

	void Init();
};