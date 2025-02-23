#pragma once
#include "../../Header.h"
class PostEffectVisAction : public Module
{
public:
	PostEffectVisAction(DWORD struct_addr, string name, XDocument * d);
	~PostEffectVisAction();

	void Init();
};