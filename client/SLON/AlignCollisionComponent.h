#pragma once
#include "../../Header.h"
class AlignCollisionComponent :
	public Module
{
public:
	AlignCollisionComponent(DWORD struct_addr, string name, XDocument * d);
	~AlignCollisionComponent();

	void Init();
};

