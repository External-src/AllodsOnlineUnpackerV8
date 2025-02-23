#include "RandomComponent.h"

RandomComponent::RandomComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Scene.RandomComponent");
	Init();
}

RandomComponent::~RandomComponent()
{
}

void RandomComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	FORCON("elements", 0x24, 0x0C)
	{
		m->OpenCon("component", 0x4);
		m->AddFloat("probability", 0x8);
	}
}
