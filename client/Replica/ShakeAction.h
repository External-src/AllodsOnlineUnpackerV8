#pragma once
#include "../../Header.h"
class ShakeAction : public Module
{
public:
	ShakeAction(DWORD struct_addr, string name, XDocument * d);
	~ShakeAction();

	void Init();
};