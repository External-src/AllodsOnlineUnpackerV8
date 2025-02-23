#pragma once
#include "../../Header.h"
class LooterEmoteAction : public Module
{
public:
	LooterEmoteAction(DWORD struct_addr, string name, XDocument * d);
	~LooterEmoteAction();

	void Init();
};