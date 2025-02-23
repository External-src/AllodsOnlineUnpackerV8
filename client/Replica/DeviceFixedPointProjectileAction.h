#pragma once
#include "../../Header.h"
class DeviceFixedPointProjectileAction : public Module
{
public:
	DeviceFixedPointProjectileAction(DWORD struct_addr, string name, XDocument * d);
	~DeviceFixedPointProjectileAction();

	void Init();
};