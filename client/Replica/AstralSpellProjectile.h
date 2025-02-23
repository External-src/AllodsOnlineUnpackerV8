#pragma once
#include "../../Header.h"
class AstralSpellProjectile : public Module
{
public:
	AstralSpellProjectile(DWORD struct_addr, string name, XDocument * d);
	~AstralSpellProjectile();

	void Init();
};