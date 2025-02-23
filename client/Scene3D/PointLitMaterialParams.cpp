#include "PointLitMaterialParams.h"

PointLitMaterialParams::PointLitMaterialParams(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Scene3D.PointLitMaterialParams");
	Init();
}


PointLitMaterialParams::~PointLitMaterialParams()
{
}

void PointLitMaterialParams::Init()
{
	AddInt("ambientColor", 0x18);
	AddInt("pointLightColor", 0x1C);
	AddVector3("pointLightPosition", 0x20);
}

