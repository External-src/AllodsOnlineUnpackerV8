#pragma once
#include "../../Header.h"
class CameraParametersAction :
	public Module
{
public:
	CameraParametersAction(DWORD struct_addr, string name, XDocument * d);
	~CameraParametersAction();

	void Init();
};

