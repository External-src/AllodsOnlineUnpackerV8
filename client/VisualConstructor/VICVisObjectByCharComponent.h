#pragma once
#include "../../Header.h"
class VICVisObjectByCharComponent : public Module
{
public:
	VICVisObjectByCharComponent(DWORD struct_addr, string name, XDocument * d);
	~VICVisObjectByCharComponent();

	void Init();
};