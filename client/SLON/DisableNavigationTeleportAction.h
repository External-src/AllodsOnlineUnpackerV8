#pragma once
#include "../../Header.h"
class DisableNavigationTeleportAction : public Module
{
public:
	DisableNavigationTeleportAction(DWORD struct_addr, string name, XDocument * d);
	~DisableNavigationTeleportAction();

	void Init();
};