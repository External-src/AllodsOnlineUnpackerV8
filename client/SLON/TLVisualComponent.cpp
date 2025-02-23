#include "TLVisualComponent.h"

TLVisualComponent::TLVisualComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.TLVisualComponent");
	Init();
}

TLVisualComponent::~TLVisualComponent()
{
}

void TLVisualComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	FORNOT("geosets", 0x24, 0x0C)
	{
		m->AddSource("Item", i);
	}
	FORNOT("texturesByTL", 0x34, 0x8)
	{
		m->AddHref("Item", i);
	}
}
