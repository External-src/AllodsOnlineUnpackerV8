#pragma once
#include "../../Header.h"
class CreatureChangeVisItemsAction : public Module
{
public:
	CreatureChangeVisItemsAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureChangeVisItemsAction();

	void Init();
};