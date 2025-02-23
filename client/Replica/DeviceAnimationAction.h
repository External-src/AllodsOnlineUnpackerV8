#pragma once
#include "../../Header.h"
class DeviceAnimationAction : public Module
{
public:
	DeviceAnimationAction(DWORD struct_addr, string name, XDocument * d);
	~DeviceAnimationAction();

	void Init();
};