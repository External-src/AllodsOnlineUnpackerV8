#pragma once
#include "../../Header.h"
class ScanerDevicePart : public Module
{
public:
	ScanerDevicePart(DWORD struct_addr, string name, XDocument * d);
	~ScanerDevicePart();

	void Init();
};