#pragma once
#include "../../Header.h"
class DeviceActiveActionComponent : public Module
{
public:
	DeviceActiveActionComponent(DWORD struct_addr, string name, XDocument * d);
	~DeviceActiveActionComponent();

	void Init();
};