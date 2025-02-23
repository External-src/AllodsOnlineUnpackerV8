#pragma once
#include "../../Header.h"
class DamageDecalManager : public Module
{
public:
	DamageDecalManager(DWORD struct_addr, string name, XDocument * d);
	~DamageDecalManager();

	void Init();
};