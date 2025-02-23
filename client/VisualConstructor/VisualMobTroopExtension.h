#pragma once
#include "../../Header.h"
class VisualMobTroopExtension :
	public Module
{
public:
	VisualMobTroopExtension(DWORD struct_addr, string name, XDocument * d);
	~VisualMobTroopExtension();

	void Init();
};

