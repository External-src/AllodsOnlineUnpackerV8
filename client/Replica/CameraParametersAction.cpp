#include "CameraParametersAction.h"

CameraParametersAction::CameraParametersAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.AttachCameraSlotComponent");
	Init();
}

CameraParametersAction::~CameraParametersAction()
{
}

void CameraParametersAction::Init()
{
	AddSource("visActionID", 0x14);
	OPENEX("parameters", 0x24)
	{
		m->AddFloat("fov", 0x4);
		m->AddFloat("maxDistance", 0x8);
		m->AddFloat("minDistance", 0x0C);
	}
}
