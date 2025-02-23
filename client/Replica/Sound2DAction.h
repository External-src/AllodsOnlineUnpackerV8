#pragma once
#include "../../Header.h"
class Sound2DAction : public Module
{
public:
	Sound2DAction(DWORD struct_addr, string name, XDocument * d);
	~Sound2DAction();

	void Init();
};