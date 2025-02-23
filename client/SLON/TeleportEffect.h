#pragma once
#include "../../Header.h"
class TeleportEffect : public Module
{
public:
	TeleportEffect(DWORD struct_addr, string name, XDocument * d);
	~TeleportEffect();

	void Init();
};