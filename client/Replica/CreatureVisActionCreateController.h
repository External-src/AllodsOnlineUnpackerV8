#pragma once
#include "../../Header.h"
class CreatureVisActionCreateController : public Module
{
public:
	CreatureVisActionCreateController(DWORD struct_addr, string name, XDocument * d);
	~CreatureVisActionCreateController();

	void Init();
};