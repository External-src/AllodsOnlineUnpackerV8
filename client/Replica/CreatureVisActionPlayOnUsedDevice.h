#pragma once
#include "../../Header.h"
class CreatureVisActionPlayOnUsedDevice : public Module
{
public:
	CreatureVisActionPlayOnUsedDevice(DWORD struct_addr, string name, XDocument * d);
	~CreatureVisActionPlayOnUsedDevice();

	void Init();
};