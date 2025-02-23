#pragma once
#include "../../Header.h"
class ProjectileHolderPart : public Module
{
public:
	ProjectileHolderPart(DWORD struct_addr, string name, XDocument * d);
	~ProjectileHolderPart();

	void Init();
};