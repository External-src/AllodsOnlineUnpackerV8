#pragma once
#include "../../Header.h"
class CreatureChargedSpellAction : public Module
{
public:
	CreatureChargedSpellAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureChargedSpellAction();

	void Init();
};