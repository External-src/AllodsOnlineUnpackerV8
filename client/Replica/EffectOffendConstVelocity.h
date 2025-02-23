#pragma once
#include "../../Header.h"
class EffectOffendConstVelocity : public Module
{
public:
	EffectOffendConstVelocity(DWORD struct_addr, string name, XDocument * d);
	~EffectOffendConstVelocity();

	void Init();
};