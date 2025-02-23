#pragma once
#include "../../Header.h"
class VICUsePack : public Module
{
public:
	VICUsePack(DWORD struct_addr, string name, XDocument * d);
	~VICUsePack();

	void Init();
};