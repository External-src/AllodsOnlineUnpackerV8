#pragma once
#include "../../Header.h"
class LevelParameter : public Module
{
public:
	LevelParameter(DWORD struct_addr, string name, XDocument * d);
	~LevelParameter();

	void Init();
};