#include "GuildColorsMaskComponent.h"

GuildColorsMaskComponent::GuildColorsMaskComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.GuildColorsMaskComponent");
	Init();
}

GuildColorsMaskComponent::~GuildColorsMaskComponent()
{
}

void GuildColorsMaskComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddHref("maskTexture", 0x24);
	FORNOT("shapeNames", 0x2C, 0x0C)
	{
		m->AddSource("Item", i);
	}
	AddText("usedShapes", Enums::GetShapes(Read(0x3C)));
	AddBool("useGuildTexture", 0x40);
}
