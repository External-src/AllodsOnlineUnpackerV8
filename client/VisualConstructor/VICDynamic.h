#pragma once
#include "../../Header.h"
class VICDynamic : public Module
{
public:
	VICDynamic(DWORD struct_addr, string name, XDocument * d);
	~VICDynamic();

	void Init();
};