#pragma once
#include "../../Header.h"
class ColorMaskComponent :
	public Module
{
public:
	ColorMaskComponent(DWORD struct_addr, string name, XDocument * d);
	~ColorMaskComponent();

	void Init();
};

