#pragma once
#include "../../Header.h"
class AttachedVisObjectComponent :
	public Module
{
public:
	AttachedVisObjectComponent(DWORD struct_addr, string name, XDocument * d);
	~AttachedVisObjectComponent();

	void Init();
};

