#pragma once
#include "../../Header.h"
class VICAttachedComponentByCharFiltered : public Module
{
public:
	VICAttachedComponentByCharFiltered(DWORD struct_addr, string name, XDocument * d);
	~VICAttachedComponentByCharFiltered();

	void Init();
};