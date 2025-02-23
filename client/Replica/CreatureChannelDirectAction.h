#pragma once
#include "../../Header.h"
class CreatureChannelDirectAction : public Module
{
public:
	CreatureChannelDirectAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureChannelDirectAction();

	void Init();
};