#pragma once
#include "../../Header.h"
class CreatureIfMainAvatarRunAction : public Module
{
public:
	CreatureIfMainAvatarRunAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureIfMainAvatarRunAction();

	void Init();
};