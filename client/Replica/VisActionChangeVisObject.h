#pragma once
#include "../../Header.h"
class VisActionChangeVisObject : public Module
{
public:
	VisActionChangeVisObject(DWORD struct_addr, string name, XDocument * d);
	~VisActionChangeVisObject();

	void Init();
};