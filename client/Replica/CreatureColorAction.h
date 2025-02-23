#pragma once
#include "../../Header.h"
class CreatureColorAction : public Module
{
public:
	CreatureColorAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureColorAction();

	void Init();
};