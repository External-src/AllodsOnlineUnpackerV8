#pragma once
#include "../../Header.h"
class DeviceHealthComponent : public Module
{
public:
	DeviceHealthComponent(DWORD struct_addr, string name, XDocument * d);
	~DeviceHealthComponent();

	void Init();
};