#pragma once
#include "../../Header.h"
class EffectOffendConstDelay : public Module
{
public:
	EffectOffendConstDelay(DWORD struct_addr, string name, XDocument * d);
	~EffectOffendConstDelay();

	void Init();
};