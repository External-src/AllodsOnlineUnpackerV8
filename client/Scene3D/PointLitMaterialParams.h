#pragma once
#include "../../Header.h"

class PointLitMaterialParams :
	public Module
{
public:
	PointLitMaterialParams(DWORD struct_addr, string name, XDocument * d);
	~PointLitMaterialParams();

	void Init();
};

