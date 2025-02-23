#pragma once
#include "../../Header.h"
class PositionSynchronizer : public Module
{
public:
	PositionSynchronizer(DWORD struct_addr, string name, XDocument * d);
	~PositionSynchronizer();

	void Init();
};