#pragma once
#include "../../Header.h"
class DeathHandler : public Module
{
public:
	DeathHandler(DWORD struct_addr, string name, XDocument * d);
	~DeathHandler();

	void Init();
};