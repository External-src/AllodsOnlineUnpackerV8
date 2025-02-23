#pragma once
#include "../../Header.h"
class CreatureReplaceAnimationsAction : public Module
{
public:
	CreatureReplaceAnimationsAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureReplaceAnimationsAction();

	void Init();
};