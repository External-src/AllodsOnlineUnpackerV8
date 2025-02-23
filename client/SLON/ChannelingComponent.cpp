#include "ChannelingComponent.h"

ChannelingComponent::ChannelingComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.ChannelingComponent");
	Init();
}


ChannelingComponent::~ChannelingComponent()
{
}

void ChannelingComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddHref("channelingFx", 0x24);
	OPENEX("endPoint", 0x2C)
	{
		m->AddText("locator", Enums::GetLocatorSlot(m->Read(0x4)));
		m->AddSource("locatorName", 0x8);
		m->AddText("member", Enums::GetMember(m->Read(0x14)));
		m->AddVector3("shift", 0x18);
	}
	AddFloat("fxLength", 0x50);
	OPENEX("startPoint", 0x54)
	{
		m->AddText("locator", Enums::GetLocatorSlot(m->Read(0x4)));
		m->AddSource("locatorName", 0x8);
		m->AddText("member", Enums::GetMember(m->Read(0x14)));
		m->AddVector3("shift", 0x18);
	}
	AddBool("scaleTextureU", 0x78);
	AddBool("scaleTextureV", 0x79);
}
