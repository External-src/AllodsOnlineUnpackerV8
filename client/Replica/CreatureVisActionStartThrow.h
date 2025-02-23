#pragma once
#include "../../Header.h"
class CreatureVisActionStartThrow : public Module
{
public:
	CreatureVisActionStartThrow(DWORD struct_addr, string name, XDocument * d);
	~CreatureVisActionStartThrow();

	void Init();
};