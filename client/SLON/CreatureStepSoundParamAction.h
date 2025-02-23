#pragma once
#include "../../Header.h"
class CreatureStepSoundParamAction : public Module
{
public:
	CreatureStepSoundParamAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureStepSoundParamAction();

	void Init();
};