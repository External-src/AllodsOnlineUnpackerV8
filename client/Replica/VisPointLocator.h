#pragma once
#include "../../Header.h"
class VisPointLocator : public Module
{
public:
	VisPointLocator(DWORD struct_addr, string name, XDocument * d);
	~VisPointLocator();

	void Init();
};