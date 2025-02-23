#pragma once
#include "../../Header.h"
class CreatureFatalityAbilityAction : public Module
{
public:
	CreatureFatalityAbilityAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureFatalityAbilityAction();

	void Init();
};