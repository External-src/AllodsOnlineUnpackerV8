#pragma once
#include "../../Header.h"
class RankInGuildParameter : public Module
{
public:
	RankInGuildParameter(DWORD struct_addr, string name, XDocument * d);
	~RankInGuildParameter();

	void Init();
};