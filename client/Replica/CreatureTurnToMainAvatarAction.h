#pragma once
#include "../../Header.h"
class CreatureTurnToMainAvatarAction : public Module
{
public:
	CreatureTurnToMainAvatarAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureTurnToMainAvatarAction();

	void Init();
};