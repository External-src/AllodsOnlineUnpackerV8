#pragma once
#include "../../Header.h"
class MimicSlotPart : public Module
{
public:
	MimicSlotPart(DWORD struct_addr, string name, XDocument * d);
	~MimicSlotPart();

	void Init();
};