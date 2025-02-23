#pragma once
#include "../../Header.h"
class SlotInterfaceData : public Module
{
public:
	SlotInterfaceData(DWORD struct_addr, string name, XDocument * d);
	~SlotInterfaceData();

	void Init();
};