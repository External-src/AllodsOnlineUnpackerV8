#include "CameraPathComponent.h"

CameraPathComponent::CameraPathComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CameraPathComponent");
	Init();

}

CameraPathComponent::~CameraPathComponent()
{
}

void CameraPathComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddHref("cameraPath", 0x24);
	AddHref("targetPath", 0x2C);
}
