#pragma once
#include "../../Header.h"
class CreatureDisableEmotesAction : public Module
{
public:
	CreatureDisableEmotesAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureDisableEmotesAction();

	void Init();
};