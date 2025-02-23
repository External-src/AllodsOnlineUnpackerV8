#pragma once
#include "../../Header.h"
class CreatureVisActionIgnoreDisarm : public Module
{
public:
	CreatureVisActionIgnoreDisarm(DWORD struct_addr, string name, XDocument * d);
	~CreatureVisActionIgnoreDisarm();

	void Init();
};