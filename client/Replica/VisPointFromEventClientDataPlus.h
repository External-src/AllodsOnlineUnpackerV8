#pragma once
#include "../../Header.h"
class VisPointFromEventClientDataPlus : public Module
{
public:
	VisPointFromEventClientDataPlus(DWORD struct_addr, string name, XDocument * d);
	~VisPointFromEventClientDataPlus();

	void Init();
};