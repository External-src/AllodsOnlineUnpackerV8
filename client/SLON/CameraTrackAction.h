#pragma once
#include "../../Header.h"
class CameraTrackAction :
	public Module
{
public:
	CameraTrackAction(DWORD struct_addr, string name, XDocument * d);
	~CameraTrackAction();

	void Init();
};

