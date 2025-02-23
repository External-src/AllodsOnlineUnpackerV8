#pragma once
#include "../../Header.h"
class VICHideUnderwear : public Module
{
public:
	VICHideUnderwear(DWORD struct_addr, string name, XDocument * d);
	~VICHideUnderwear();

	void Init();
};