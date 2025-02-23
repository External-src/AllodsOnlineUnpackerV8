#pragma once
#include "../../Header.h"
class CreatureTimeIntervalChannelSpeedAction : public Module
{
public:
	CreatureTimeIntervalChannelSpeedAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureTimeIntervalChannelSpeedAction();

	void Init();
};