#pragma once
#include "../../Header.h"
class VisActionRandom : public Module
{
public:
	VisActionRandom(DWORD struct_addr, string name, XDocument * d);
	~VisActionRandom();

	void Init();
};