#pragma once
#include "../../Header.h"

class AstralMaterialParams :
	public Module
{
public:
	AstralMaterialParams(DWORD struct_addr, string name, XDocument * d);
	~AstralMaterialParams();

	void Init();
};

