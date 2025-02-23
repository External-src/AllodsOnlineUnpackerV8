#pragma once
#include "../../Header.h"
class ShipEngineComponent : public Module
{
public:
	ShipEngineComponent(DWORD struct_addr, string name, XDocument * d);
	~ShipEngineComponent();

	void Init();
};