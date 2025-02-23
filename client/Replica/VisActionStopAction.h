#pragma once
#include "../../Header.h"
class VisActionStopAction : public Module
{
public:
	VisActionStopAction(DWORD struct_addr, string name, XDocument * d);
	~VisActionStopAction();

	void Init();
};