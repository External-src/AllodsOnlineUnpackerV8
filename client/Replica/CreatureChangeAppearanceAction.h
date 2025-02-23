#pragma once
#include "../../Header.h"
class CreatureChangeAppearanceAction : public Module
{
public:
	CreatureChangeAppearanceAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureChangeAppearanceAction();

	void Init();
};