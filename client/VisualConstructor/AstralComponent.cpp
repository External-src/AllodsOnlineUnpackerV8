#include "AstralComponent.h"

AstralComponent::AstralComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.AstralComponent");
	Init();
}

AstralComponent::~AstralComponent()
{
}

void AstralComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddHref("astralObject", 0x24);
}
