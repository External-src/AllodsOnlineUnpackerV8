#pragma once
#include "../../Header.h"
class CreatureScaleAction : public Module
{
public:
	CreatureScaleAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureScaleAction();

	void Init();
};