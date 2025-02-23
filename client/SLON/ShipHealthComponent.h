#pragma once
#include "../../Header.h"
class ShipHealthComponent : public Module
{
public:
	ShipHealthComponent(DWORD struct_addr, string name, XDocument * d);
	~ShipHealthComponent();

	void Init();
};