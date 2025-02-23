#pragma once
#include "../../Header.h"
class VICSelectComponentByGuildLevel : public Module
{
public:
	VICSelectComponentByGuildLevel(DWORD struct_addr, string name, XDocument * d);
	~VICSelectComponentByGuildLevel();

	void Init();
};