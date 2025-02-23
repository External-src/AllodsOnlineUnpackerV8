#pragma once
#include "../../Header.h"
class UsableDeviceClientPart : public Module
{
public:
	UsableDeviceClientPart(DWORD struct_addr, string name, XDocument * d);
	~UsableDeviceClientPart();

	void Init();
};