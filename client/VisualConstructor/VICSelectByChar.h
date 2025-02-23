#pragma once
#include "../../Header.h"
class VICSelectByChar : public Module
{
public:
	VICSelectByChar(DWORD struct_addr, string name, XDocument * d);
	~VICSelectByChar();

	void Init();
};