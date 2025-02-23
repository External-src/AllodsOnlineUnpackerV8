#pragma once
#include "../../Header.h"
class VICCancelDefaultDressSlotSettings : public Module
{
public:
	VICCancelDefaultDressSlotSettings(DWORD struct_addr, string name, XDocument * d);
	~VICCancelDefaultDressSlotSettings();

	void Init();
};