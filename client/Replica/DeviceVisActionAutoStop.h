#pragma once
#include "../../Header.h"
class DeviceVisActionAutoStop : public Module
{
public:
	DeviceVisActionAutoStop(DWORD struct_addr, string name, XDocument * d);
	~DeviceVisActionAutoStop();

	void Init();
};