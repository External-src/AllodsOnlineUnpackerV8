#pragma once
#include "../../Header.h"
class AstralHubObjectPart : public Module
{
public:
	AstralHubObjectPart(DWORD struct_addr, string name, XDocument * d);
	~AstralHubObjectPart();

	void Init();
};