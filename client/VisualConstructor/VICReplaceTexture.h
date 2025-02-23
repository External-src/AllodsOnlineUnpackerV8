#pragma once
#include "../../Header.h"
class VICReplaceTexture : public Module
{
public:
	VICReplaceTexture(DWORD struct_addr, string name, XDocument * d);
	~VICReplaceTexture();

	void Init();
};