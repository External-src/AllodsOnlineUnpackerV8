#pragma once
#include "../../Header.h"
class PirateSailsPart : public Module
{
public:
	PirateSailsPart(DWORD struct_addr, string name, XDocument * d);
	~PirateSailsPart();

	void Init();
};