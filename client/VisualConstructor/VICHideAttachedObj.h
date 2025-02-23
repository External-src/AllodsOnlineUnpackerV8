#pragma once
#include "../../Header.h"
class VICHideAttachedObj : public Module
{
public:
	VICHideAttachedObj(DWORD struct_addr, string name, XDocument * d);
	~VICHideAttachedObj();

	void Init();
};