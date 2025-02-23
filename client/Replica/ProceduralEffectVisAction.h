#pragma once
#include "../../Header.h"
class ProceduralEffectVisAction : public Module
{
public:
	ProceduralEffectVisAction(DWORD struct_addr, string name, XDocument * d);
	~ProceduralEffectVisAction();

	void Init();
};