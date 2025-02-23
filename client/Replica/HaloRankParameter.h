#pragma once
#include "../../Header.h"
class HaloRankParameter : public Module
{
public:
	HaloRankParameter(DWORD struct_addr, string name, XDocument * d);
	~HaloRankParameter();

	void Init();
};