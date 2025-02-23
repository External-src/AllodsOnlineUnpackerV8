#pragma once
#include "../../../Header.h"
class OverLevelPenaltyCalcer : public Module
{
public:
	OverLevelPenaltyCalcer(DWORD struct_addr, string name, XDocument * d);
	~OverLevelPenaltyCalcer();

	void Init();
};