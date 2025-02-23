#pragma once
#include "../../Header.h"
class AstralSpellChanneling :
	public Module
{
public:
	AstralSpellChanneling(DWORD struct_addr, string name, XDocument * d);
	~AstralSpellChanneling();

	void Init();
};