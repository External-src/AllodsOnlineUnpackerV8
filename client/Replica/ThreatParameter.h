#pragma once
#include "../../Header.h"
class ThreatParameter : public Module
{
public:
	ThreatParameter(DWORD struct_addr, string name, XDocument * d);
	~ThreatParameter();

	void Init();
};