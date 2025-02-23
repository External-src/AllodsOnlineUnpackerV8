#pragma once
#include "../../Header.h"
class SphereCollisionHandler : public Module
{
public:
	SphereCollisionHandler(DWORD struct_addr, string name, XDocument * d);
	~SphereCollisionHandler();

	void Init();
};