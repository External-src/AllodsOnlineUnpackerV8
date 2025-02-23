#pragma once
#include "../../Header.h"
class CameraPathComponent :
	public Module
{
public:
	CameraPathComponent(DWORD struct_addr, string name, XDocument * d);
	~CameraPathComponent();

	void Init();
};

