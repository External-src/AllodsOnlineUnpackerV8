#pragma once
#include "../../Header.h"

class CommonMaterialParams :
	public Module
{
public:
	CommonMaterialParams(DWORD struct_addr, string name, XDocument * d);
	~CommonMaterialParams();

	void Init();
};

