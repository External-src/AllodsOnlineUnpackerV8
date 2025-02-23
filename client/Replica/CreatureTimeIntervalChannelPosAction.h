#pragma once
#include "../../Header.h"
class CreatureTimeIntervalChannelPosAction : public Module
{
public:
	CreatureTimeIntervalChannelPosAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureTimeIntervalChannelPosAction();

	void Init();
};