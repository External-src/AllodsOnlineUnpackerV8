#include "VICOverride.h"

VICOverride::VICOverride(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICOverride");
	Init();
}

VICOverride::~VICOverride()
{
}

void VICOverride::Init()
{
	AddText("itemPriority", Enums::GetItemPriority(Read(0x18)));
	FORCON("visItems", 0x1C, 0x10)
	{
		m->AddText("dressSlot", Enums::GetSlot(m->Read(0x4)));
		m->AddHref("visItem", 0x8);
	}
	AddBool("cancelDefaultDressSlotSettings", 0x2C);
}