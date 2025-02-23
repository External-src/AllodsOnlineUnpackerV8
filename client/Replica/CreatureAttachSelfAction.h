#pragma once
#include "../../Header.h"
class CreatureAttachSelfAction : public Module
{
public:
	CreatureAttachSelfAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureAttachSelfAction();

	void Init();
};