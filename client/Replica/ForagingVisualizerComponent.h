#pragma once
#include "../../Header.h"
class ForagingVisualizerComponent : public Module
{
public:
	ForagingVisualizerComponent(DWORD struct_addr, string name, XDocument * d);
	~ForagingVisualizerComponent();

	void Init();
};