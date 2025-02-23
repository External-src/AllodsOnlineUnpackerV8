#include "ColorMaskComponent.h"

ColorMaskComponent::ColorMaskComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Scene.ColorMaskComponent");
	Init();
}

ColorMaskComponent::~ColorMaskComponent()
{
}

void ColorMaskComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddHref("maskTexture", 0x24);
	AddInt("primaryColor", 0x2C);
	AddInt("secondaryColor", 0x30);
	FORNOT("shapeNames", 0x34, 0x0C)
	{
		m->AddSource("Item", i);
	}
}
