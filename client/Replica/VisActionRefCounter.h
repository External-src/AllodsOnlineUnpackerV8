#pragma once
#include "../../Header.h"
class VisActionRefCounter : public Module
{
public:
	VisActionRefCounter(DWORD struct_addr, string name, XDocument * d);
	~VisActionRefCounter();

	void Init();
};