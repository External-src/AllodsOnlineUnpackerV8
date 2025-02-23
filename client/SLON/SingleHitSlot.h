#pragma once
#include "../../Header.h"
class SingleHitSlot : public Module
{
public:
	SingleHitSlot(DWORD struct_addr, string name, XDocument * d);
	~SingleHitSlot();

	void Init();
};