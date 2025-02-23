#pragma once
#include "../../Header.h"
class SlotLink : public Module
{
public:
	SlotLink(DWORD struct_addr, string name, XDocument * d);
	~SlotLink();

	void Init();
};