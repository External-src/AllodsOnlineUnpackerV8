#include "ShipSkin.h"

ShipSkin::ShipSkin(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

ShipSkin::~ShipSkin()
{
}

void ShipSkin::Init()
{
	OPENEX("customization", 0x18)
	{
		FORCONX("slots", 0x4, 0x18)
		{
			FORCONX("devices", 0x4, 0x10)
			{
				m->AddInt("price", 0x4);
				m->AddHref("resource", 0x8);
			}
			m->AddText("slot", Enums::GetSlotShip(m->Read(0x14)));
		}
	}
	AddHref("defaultItem", 0x2C);
	AddTxt("description", 0x34);
	AddHref("image", 0x44);
	AddHref("interiorVisObject", 0x4C);
	AddTxt("name", 0x54);
	FORNOT("parts", 0x64, 0x4)
	{
		m->OpenCon("Item", i);
	}
	AddHref("staticObj", 0x74);
	AddHref("unlock", 0x7C);
}