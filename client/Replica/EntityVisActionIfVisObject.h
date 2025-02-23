#pragma once
#include "../../Header.h"
class EntityVisActionIfVisObject : public Module
{
public:
	EntityVisActionIfVisObject(DWORD struct_addr, string name, XDocument * d);
	~EntityVisActionIfVisObject();

	void Init();
};