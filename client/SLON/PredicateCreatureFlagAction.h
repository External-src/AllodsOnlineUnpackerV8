#pragma once
#include "../../Header.h"
class PredicateCreatureFlagAction : public Module
{
public:
	PredicateCreatureFlagAction(DWORD struct_addr, string name, XDocument * d);
	~PredicateCreatureFlagAction();

	void Init();
};