#pragma once
#include "../../Header.h"
class VisItemEffectsRanged : public Module
{
public:
	VisItemEffectsRanged(DWORD struct_addr, string name, XDocument * d);
	~VisItemEffectsRanged();

	void Init();
};