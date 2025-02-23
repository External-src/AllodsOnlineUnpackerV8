#include "SkyMaterialParams.h"



SkyMaterialParams::SkyMaterialParams(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Scene3D.SkyMaterialParams");
	Init();
}


SkyMaterialParams::~SkyMaterialParams()
{
}

void SkyMaterialParams::Init()
{
	AddHref("bumpTexture", 0x18);
	AddBool("bumped", 0x20);
}
