#include "LightComponent.h"

LightComponent::LightComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Scene.LightComponent");
	Init();
}

LightComponent::~LightComponent()
{
}

void LightComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddFloat("attenuationPower", 0x24);
	AddVector3("direction", 0x28);
	AddHref("editorVisObj", 0x34);
	AddFloat("facingValue", 0x3C);
	AddFloat("intensity", 0x40);
	AddFloat("intensityRandom", 0x44);
	AddVector3("pivot", 0x48);
	AddFloat("radius", 0x54);
}
