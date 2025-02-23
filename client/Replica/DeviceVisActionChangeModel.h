#pragma once
#include "../../Header.h"
class DeviceVisActionChangeModel : public Module
{
public:
	DeviceVisActionChangeModel(DWORD struct_addr, string name, XDocument * d);
	~DeviceVisActionChangeModel();

	void Init();
};