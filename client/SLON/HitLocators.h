#pragma once
#include "../../Header.h"
class HitLocators : public Module
{
public:
	HitLocators(DWORD struct_addr, string name, XDocument * d);
	~HitLocators();

	void Init();
};