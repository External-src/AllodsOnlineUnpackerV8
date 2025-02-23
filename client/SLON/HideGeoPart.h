#pragma once
#include "../../Header.h"
class HideGeoPart : public Module
{
public:
	HideGeoPart(DWORD struct_addr, string name, XDocument * d);
	~HideGeoPart();

	void Init();
};