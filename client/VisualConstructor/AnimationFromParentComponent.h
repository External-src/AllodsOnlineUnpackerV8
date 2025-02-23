#pragma once
#include "../../Header.h"
class AnimationFromParentComponent :
	public Module
{
public:
	AnimationFromParentComponent(DWORD struct_addr, string name, XDocument * d);
	~AnimationFromParentComponent();

	void Init();
};

