#pragma once
#include "../../Header.h"
class HighlightCreatureVisAction : public Module
{
public:
	HighlightCreatureVisAction(DWORD struct_addr, string name, XDocument * d);
	~HighlightCreatureVisAction();

	void Init();
};