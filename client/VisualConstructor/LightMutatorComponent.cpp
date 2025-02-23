#include "LightMutatorComponent.h"

LightMutatorComponent::LightMutatorComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.LightMutatorComponent");
	Init();
}

LightMutatorComponent::~LightMutatorComponent()
{
}

void LightMutatorComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddHref("animatedParameters", 0x24);
}
