#pragma once
#include "../../Header.h"
class DeviceVisActionList : public Module
{
public:
	DeviceVisActionList(DWORD struct_addr, string name, XDocument * d);
	~DeviceVisActionList();

	void Init();
};