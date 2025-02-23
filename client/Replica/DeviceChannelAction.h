#pragma once
#include "../../Header.h"
class DeviceChannelAction : public Module
{
public:
	DeviceChannelAction(DWORD struct_addr, string name, XDocument * d);
	~DeviceChannelAction();

	void Init();
};