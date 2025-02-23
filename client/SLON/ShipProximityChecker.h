#pragma once
#include "../../Header.h"
class ShipProximityChecker : public Module
{
public:
	ShipProximityChecker(DWORD struct_addr, string name, XDocument * d);
	~ShipProximityChecker();

	void Init();
};