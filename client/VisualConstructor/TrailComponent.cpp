#include "TrailComponent.h"

TrailComponent::TrailComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.TrailComponent");
	Init();
}

TrailComponent::~TrailComponent()
{
}

void TrailComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddHref("trail", 0x24);
}