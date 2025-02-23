#pragma once
#include "../../Header.h"
class CreatureRunVisActionResource : public Module
{
public:
	CreatureRunVisActionResource(DWORD struct_addr, string name, XDocument * d);
	~CreatureRunVisActionResource();

	void Init();
};