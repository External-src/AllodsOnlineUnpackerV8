#pragma once
#include "../../Header.h"
class ClolorFromPrimeSecondary : public Module
{
public:
	ClolorFromPrimeSecondary(DWORD struct_addr, string name, XDocument * d);
	~ClolorFromPrimeSecondary();

	void Init();
};