#pragma once
#include "../../Header.h"
class CreatureMusicParamAction : public Module
{
public:
	CreatureMusicParamAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureMusicParamAction();

	void Init();
};