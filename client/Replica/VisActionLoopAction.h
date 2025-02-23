#pragma once
#include "../../Header.h"
class VisActionLoopAction : public Module
{
public:
	VisActionLoopAction(DWORD struct_addr, string name, XDocument * d);
	~VisActionLoopAction();

	void Init();
};