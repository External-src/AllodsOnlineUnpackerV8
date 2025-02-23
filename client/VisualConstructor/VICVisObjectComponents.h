#pragma once
#include "../../Header.h"
class VICVisObjectComponents : public Module
{
public:
	VICVisObjectComponents(DWORD struct_addr, string name, XDocument * d);
	~VICVisObjectComponents();

	void Init();
};