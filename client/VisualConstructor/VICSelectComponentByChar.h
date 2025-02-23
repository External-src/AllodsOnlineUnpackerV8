#pragma once
#include "../../Header.h"
class VICSelectComponentByChar : public Module
{
public:
	VICSelectComponentByChar(DWORD struct_addr, string name, XDocument * d);
	~VICSelectComponentByChar();

	void Init();
};