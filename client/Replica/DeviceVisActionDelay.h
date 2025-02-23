#pragma once
#include "../../Header.h"
class DeviceVisActionDelay : public Module
{
public:
	DeviceVisActionDelay(DWORD struct_addr, string name, XDocument * d);
	~DeviceVisActionDelay();

	void Init();
};