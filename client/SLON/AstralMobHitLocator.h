#pragma once
#include "../../Header.h"
class AstralMobHitLocator : public Module
{
public:
	AstralMobHitLocator(DWORD struct_addr, string name, XDocument * d);
	~AstralMobHitLocator();

	void Init();
};