#pragma once
#include "../../Header.h"
class ShipDeviceManager : public Module
{
public:
	ShipDeviceManager(DWORD struct_addr, string name, XDocument * d);
	~ShipDeviceManager();

	void Init();
};