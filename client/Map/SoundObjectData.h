#pragma once
#include "../../Header.h"
class SoundObjectData : public Module
{
public:
	SoundObjectData(DWORD struct_addr, string name, XDocument * d);
	~SoundObjectData();

	void Init();
};