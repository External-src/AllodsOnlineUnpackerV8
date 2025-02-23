#pragma once
#include "../../Header.h"
class CreatureWaitThrowDurationAction : public Module
{
public:
	CreatureWaitThrowDurationAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureWaitThrowDurationAction();

	void Init();
};