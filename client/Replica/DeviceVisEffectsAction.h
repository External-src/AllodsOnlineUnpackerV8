#pragma once
#include "../../Header.h"
class DeviceVisEffectsAction : public Module
{
public:
	DeviceVisEffectsAction(DWORD struct_addr, string name, XDocument * d);
	~DeviceVisEffectsAction();

	void Init();
};