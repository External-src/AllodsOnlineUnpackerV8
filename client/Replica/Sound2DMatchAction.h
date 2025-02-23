#pragma once
#include "../../Header.h"
class Sound2DMatchAction : public Module
{
public:
	Sound2DMatchAction(DWORD struct_addr, string name, XDocument * d);
	~Sound2DMatchAction();

	void Init();
};