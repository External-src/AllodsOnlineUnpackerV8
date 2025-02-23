#pragma once
#include "../../Header.h"
class CreatureVisObjectComponentsAction : public Module
{
public:
	CreatureVisObjectComponentsAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureVisObjectComponentsAction();

	void Init();
};