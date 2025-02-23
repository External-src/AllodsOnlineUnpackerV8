#pragma once
#include "../../Header.h"
class DeviceCannonLaunchedAction : public Module
{
public:
	DeviceCannonLaunchedAction(DWORD struct_addr, string name, XDocument * d);
	~DeviceCannonLaunchedAction();

	void Init();
};