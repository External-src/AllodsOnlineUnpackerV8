#pragma once
#include "../../Header.h"
class DeviceRotationPart : public Module
{
public:
	DeviceRotationPart(DWORD struct_addr, string name, XDocument * d);
	~DeviceRotationPart();

	void Init();
};