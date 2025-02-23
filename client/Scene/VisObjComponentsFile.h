#pragma once
#include "../../Header.h"
class VisObjComponentsFile :
	public Module
{
public:
	VisObjComponentsFile(DWORD struct_addr, string name, XDocument * d);
	~VisObjComponentsFile();

	void Init();
};

