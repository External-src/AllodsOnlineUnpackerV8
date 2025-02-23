#pragma once
#include "../../Header.h"
class VisActionDelay : public Module
{
public:
	VisActionDelay(DWORD struct_addr, string name, XDocument * d);
	~VisActionDelay();

	void Init();
};