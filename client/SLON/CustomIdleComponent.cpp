#include "CustomIdleComponent.h"

CustomIdleComponent::CustomIdleComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CustomIdleComponent");
	Init();
}

CustomIdleComponent::~CustomIdleComponent()
{
}

void CustomIdleComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	FORNOT("animations", 0x24, 0x4)
	{
		m->AddText("Item", Enums::GetAnimation(m->Read(i)));
	}
	AddFloat("timeMax", 0x34);
	AddFloat("timeMin", 0x38);
}
