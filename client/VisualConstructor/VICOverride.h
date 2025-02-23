#pragma once
#include "../../Header.h"
class VICOverride : public Module
{
public:
	VICOverride(DWORD struct_addr, string name, XDocument * d);
	~VICOverride();

	void Init();
};