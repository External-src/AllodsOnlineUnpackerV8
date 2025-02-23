#pragma once
#include "../../Header.h"
class Sound3DAction : public Module
{
public:
	Sound3DAction(DWORD struct_addr, string name, XDocument * d);
	~Sound3DAction();

	void Init();
};