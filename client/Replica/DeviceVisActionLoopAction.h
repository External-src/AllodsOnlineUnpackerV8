#pragma once
#include "../../Header.h"
class DeviceVisActionLoopAction : public Module
{
public:
	DeviceVisActionLoopAction(DWORD struct_addr, string name, XDocument * d);
	~DeviceVisActionLoopAction();

	void Init();
};