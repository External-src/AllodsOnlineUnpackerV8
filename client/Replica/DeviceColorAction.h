#pragma once
#include "../../Header.h"
class DeviceColorAction : public Module
{
public:
	DeviceColorAction(DWORD struct_addr, string name, XDocument * d);
	~DeviceColorAction();

	void Init();
};