#pragma once
#include "../../Header.h"
class CreatureParalyzeAction : public Module
{
public:
	CreatureParalyzeAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureParalyzeAction();

	void Init();
};