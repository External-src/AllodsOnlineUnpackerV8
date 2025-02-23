#pragma once
#include "../../Header.h"
class AstralComponent :
	public Module
{
public:
	AstralComponent(DWORD struct_addr, string name, XDocument * d);
	~AstralComponent();

	void Init();
};

