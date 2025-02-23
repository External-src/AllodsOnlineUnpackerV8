#pragma once
#include "../../Header.h"
class TLVisualComponent :
	public Module
{
public:
	TLVisualComponent(DWORD struct_addr, string name, XDocument * d);
	~TLVisualComponent();

	void Init();
};

