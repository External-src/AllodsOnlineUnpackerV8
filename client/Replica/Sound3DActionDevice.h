#pragma once
#include "../../Header.h"
class Sound3DActionDevice : public Module
{
public:
	Sound3DActionDevice(DWORD struct_addr, string name, XDocument * d);
	~Sound3DActionDevice();

	void Init();
};