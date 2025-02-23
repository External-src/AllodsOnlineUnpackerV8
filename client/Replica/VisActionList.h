#pragma once
#include "../../Header.h"
class VisActionList : public Module
{
public:
	VisActionList(DWORD struct_addr, string name, XDocument * d);
	~VisActionList();

	void Init();
};