#pragma once
#include "../../Header.h"
class CreatureAstralSpellFXVisAction :
	public Module
{
public:
	CreatureAstralSpellFXVisAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureAstralSpellFXVisAction();

	void Init();
};

