#pragma once
#include "../../Header.h"
class VICSelectComponentByRankInGuild : public Module
{
public:
	VICSelectComponentByRankInGuild(DWORD struct_addr, string name, XDocument * d);
	~VICSelectComponentByRankInGuild();

	void Init();
};