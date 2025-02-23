#pragma once
#include "../../Header.h"
class CreatureItemAttachBoneAction : public Module
{
public:
	CreatureItemAttachBoneAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureItemAttachBoneAction();

	void Init();
};