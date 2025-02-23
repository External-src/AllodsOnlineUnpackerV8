#include "CameraTrackAction.h"

CameraTrackAction::CameraTrackAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CameraTrackAction");
	Init();
}

CameraTrackAction::~CameraTrackAction()
{
}

void CameraTrackAction::Init()
{
	AddSource("visActionID", 0x14);
	FORCON("cameraPoints", 0x24, 0x14)
	{
		m->AddFloat("duration", 0x4);
		m->AddVector3("position", 0x8);
	}
	AddHref("cameraRoute", 0x34);
	AddFloat("routeDuration", 0x3C);
	FORCON("targetPoints", 0x40, 0x14)
	{
		m->AddFloat("duration", 0x4);
		m->AddVector3("position", 0x8);
	}
	AddHref("targetRoute", 0x50);
}
