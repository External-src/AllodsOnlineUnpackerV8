#pragma once
#include "../../Header.h"
class CreatureForceMoveAction : public Module
{
public:
	CreatureForceMoveAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureForceMoveAction();

	void Init();
};