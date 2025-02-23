#pragma once
#include "../../Header.h"
class InteractionAnimationPart : public Module
{
public:
	InteractionAnimationPart(DWORD struct_addr, string name, XDocument * d);
	~InteractionAnimationPart();

	void Init();
};