#pragma once
#include "../../Header.h"
class DeviceVisibilityComponent : public Module
{
public:
	DeviceVisibilityComponent(DWORD struct_addr, string name, XDocument * d);
	~DeviceVisibilityComponent();

	void Init();
};