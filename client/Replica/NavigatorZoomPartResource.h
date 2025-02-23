#pragma once
#include "../../Header.h"
class NavigatorZoomPartResource : public Module
{
public:
	NavigatorZoomPartResource(DWORD struct_addr, string name, XDocument * d);
	~NavigatorZoomPartResource();

	void Init();
};