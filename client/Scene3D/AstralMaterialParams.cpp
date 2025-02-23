#include "AstralMaterialParams.h"



AstralMaterialParams::AstralMaterialParams(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Scene3D.AstralMaterialParams");
	Init();
}


AstralMaterialParams::~AstralMaterialParams()
{
}

void AstralMaterialParams::Init()
{
	AddInt("contourColorModifier", 0x18);
	AddInt("specularColorModifier", 0x1C);
	AddFloat("textureBlendWeight", 0x20);
}
