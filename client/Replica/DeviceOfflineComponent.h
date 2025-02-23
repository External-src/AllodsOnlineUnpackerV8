#pragma once
#include "../../Header.h"
class DeviceOfflineComponent : public Module
{
public:
	DeviceOfflineComponent(DWORD struct_addr, string name, XDocument * d);
	~DeviceOfflineComponent();

	void Init();
};