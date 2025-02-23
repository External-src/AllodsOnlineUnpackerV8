#pragma once
#include "../../Header.h"
class CreatureCancelMountHidingVisAction : public Module
{
public:
	CreatureCancelMountHidingVisAction(DWORD struct_addr, string name, XDocument * d);
	~CreatureCancelMountHidingVisAction();

	void Init();
};