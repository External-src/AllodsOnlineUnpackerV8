#include "CommonMaterialParams.h"

CommonMaterialParams::CommonMaterialParams(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Scene3D.CommonMaterialParams");
	Init();
}


CommonMaterialParams::~CommonMaterialParams()
{
}

void CommonMaterialParams::Init()
{
	AddHref("bumpTexture", 0x18);
	AddInt("color", 0x20);
	AddInt("contourColorModifier", 0x24);
	AddHref("effectMaskTexture", 0x28);
	AddHref("envReflectionTexture", 0x30);
	AddHref("envSpecularTexture", 0x38);
	AddFloat("shininess", 0x40);
	AddInt("specularColorModifier", 0x44);
	AddFloat("specularIntensity", 0x48);
	AddBool("bumpDisabled", 0x4C);
	AddBool("selfillum", 0x4D);
	AddBool("useEnvContourColorFactor", 0x4E);
	AddBool("useEnvSpecularColorFactor", 0x4F);
	AddBool("useMaskColor", 0x50);
	AddBool("vertexBakedLight", 0x51);
}
