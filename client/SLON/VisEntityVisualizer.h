#pragma once
#include "../../Header.h"
class VisEntityVisualizer : public Module
{
public:
	VisEntityVisualizer(DWORD struct_addr, string name, XDocument * d);
	~VisEntityVisualizer();

	void Init();
};