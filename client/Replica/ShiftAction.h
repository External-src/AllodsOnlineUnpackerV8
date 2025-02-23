#pragma once
#include "../../Header.h"
class ShiftAction : public Module
{
public:
	ShiftAction(DWORD struct_addr, string name, XDocument * d);
	~ShiftAction();

	void Init();
};