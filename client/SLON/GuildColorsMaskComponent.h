#pragma once
#include "../../Header.h"
class GuildColorsMaskComponent :
	public Module
{
public:
	GuildColorsMaskComponent(DWORD struct_addr, string name, XDocument * d);
	~GuildColorsMaskComponent();

	void Init();
};

