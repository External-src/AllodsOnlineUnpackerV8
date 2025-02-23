#pragma once
#include "../../Header.h"
class TLScriptsPart : public Module
{
public:
	TLScriptsPart(DWORD struct_addr, string name, XDocument * d);
	~TLScriptsPart();

	void Init();
};