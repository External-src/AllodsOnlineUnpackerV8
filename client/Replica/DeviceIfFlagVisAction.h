#pragma once
#include "../../Header.h"
class DeviceIfFlagVisAction : public Module
{
public:
	DeviceIfFlagVisAction(DWORD struct_addr, string name, XDocument * d);
	~DeviceIfFlagVisAction();

	void Init();
};