#pragma once
#include "../../Header.h"
class ChainAnimatorComponent :
	public Module
{
public:
	ChainAnimatorComponent(DWORD struct_addr, string name, XDocument * d);
	~ChainAnimatorComponent();
	
	void Init();
};

