#pragma once
#include "../../Header.h"
class ShowSceneAction : public Module
{
public:
	ShowSceneAction(DWORD struct_addr, string name, XDocument * d);
	~ShowSceneAction();

	void Init();
};