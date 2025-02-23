#pragma once
#include "../../Header.h"
class VisualItemGrades : public Module
{
public:
	VisualItemGrades(DWORD struct_addr, string name, XDocument * d);
	~VisualItemGrades();

	void Init();
};