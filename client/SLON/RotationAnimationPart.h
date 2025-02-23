#pragma once
#include "../../Header.h"
class RotationAnimationPart : public Module
{
public:
	RotationAnimationPart(DWORD struct_addr, string name, XDocument * d);
	~RotationAnimationPart();

	void Init();
};