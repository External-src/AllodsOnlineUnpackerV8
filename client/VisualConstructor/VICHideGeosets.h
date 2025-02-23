#pragma once
#include "../../Header.h"
class VICHideGeosets : public Module
{
public:
	VICHideGeosets(DWORD struct_addr, string name, XDocument * d);
	~VICHideGeosets();

	void Init();
};