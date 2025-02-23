#include "SunShaftsComponent.h"

SunShaftsComponent::SunShaftsComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.SunShaftsComponent");
	Init();
}

SunShaftsComponent::~SunShaftsComponent()
{
}

void SunShaftsComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddSource("materialBindName", 0x24);
	AddSource("pivotName", 0x30);
	AddSource("slotName", 0x3C);
	AddHref("sunShafts", 0x48);
}
