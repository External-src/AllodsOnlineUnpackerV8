#pragma once
#include "../../Header.h"
class AttachCameraSlotComponent :
	public Module
{
public:
	AttachCameraSlotComponent(DWORD struct_addr, string name, XDocument * d);
	~AttachCameraSlotComponent();
	void Init();
};

