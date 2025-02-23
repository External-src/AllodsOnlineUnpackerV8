#pragma once
#include "../../Header.h"

class SkyMaterialParams :
	public Module
{
public:
	SkyMaterialParams(DWORD struct_addr, string name, XDocument * d);
	~SkyMaterialParams();

	void Init();
};

