#include "SkyObject.h"

SkyObject::SkyObject(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.SkyObject");
	Init();
}

SkyObject::~SkyObject()
{
}

void SkyObject::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddFloat("fadeDistanceEnd", 0x24);
	AddFloat("fadeDistanceStart", 0x28);
	AddBool("useSceneFog", 0x2C);
	AddBool("useSkySphereRadius", 0x2D);
	AddBool("useSoftClipping", 0x2E);
}
