#pragma once
#include "../../Header.h"
class CreatureSceneDesaturationAction : public Module
{
public:
	CreatureSceneDesaturationAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureSceneDesaturationAction();

	void Init();
};