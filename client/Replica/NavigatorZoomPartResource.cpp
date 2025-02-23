#include "NavigatorZoomPartResource.h"

NavigatorZoomPartResource::NavigatorZoomPartResource(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.NavigatorZoomPartResource");
	Init();
}

NavigatorZoomPartResource::~NavigatorZoomPartResource()
{
}

void NavigatorZoomPartResource::Init()
{
	OPENEX("zoomViewSight", 0x18)
	{
		m->AddHref("camera", 0x4);
		m->AddFloat("distance", 0x0C);
		m->AddFloat("fogEnd", 0x10);
		m->AddFloat("fogStart", 0x14);
		m->AddFloat("fov", 0x18);
		m->AddVector3("position", 0x1C);
		m->AddRotation3("rotation", 0x28);
		m->AddFloat("softFaderEnd", 0x38);
		m->AddFloat("softFaderStart", 0x3C);
		m->AddBool("hasCrosshair", 0x40);
		m->AddBool("isBinding", 0x41);
	}
}