#pragma once
#include "../../Header.h"
class CreatureEnlargeFovAction : public Module
{
public:
	CreatureEnlargeFovAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureEnlargeFovAction();

	void Init();
};