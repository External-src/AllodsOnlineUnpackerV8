#pragma once
#include "../../Header.h"
class VICStatic : public Module
{
public:
	VICStatic(DWORD struct_addr, string name, XDocument * d);
	~VICStatic();

	void Init();
};