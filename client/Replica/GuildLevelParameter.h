#pragma once
#include "../../Header.h"
class GuildLevelParameter : public Module
{
public:
	GuildLevelParameter(DWORD struct_addr, string name, XDocument * d);
	~GuildLevelParameter();

	void Init();
};