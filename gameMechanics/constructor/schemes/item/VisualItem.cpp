#include "VisualItem.h"

VisualItem::VisualItem(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

VisualItem::~VisualItem()
{
}

void VisualItem::Init()
{
	OPENEX("armorShapes", 0x18)
	{
		FORCONX("female", 0x4, 0x34)
		{
			m->AddHref("armorScene", 0x4);
			m->AddInt("color", 0x0C);
			m->AddSource("locatorName", 0x10);
			m->AddInt("maskColor", 0x1C);
			m->AddHref("replacement", 0x20);
			m->AddSource("shapeName", 0x28);
		}
		FORCONX("male", 0x14, 0x34)
		{
			m->AddHref("armorScene", 0x4);
			m->AddInt("color", 0x0C);
			m->AddSource("locatorName", 0x10);
			m->AddInt("maskColor", 0x1C);
			m->AddHref("replacement", 0x20);
			m->AddSource("shapeName", 0x28);
		}
		FORCONX("unisex", 0x24, 0x34)
		{
			m->AddHref("armorScene", 0x4);
			m->AddInt("color", 0x0C);
			m->AddSource("locatorName", 0x10);
			m->AddInt("maskColor", 0x1C);
			m->AddHref("replacement", 0x20);
			m->AddSource("shapeName", 0x28);
		}
	}
	AddHref("braTexturePatches", 0x4C);
	FORNOT("componentPacks", 0x54, 0x8)
	{
		m->AddHref("Item", i);
	}
	FORNOT("disabledGeosets", 0x64, 0x0C)
	{
		m->AddSource("Item", i);
	}
	AddText("dressSlot", Enums::GetSlot(Read(0x74)));
	OPENEX("dualWield", 0x78)
	{
		m->AddHref("mainHandItem", 0x4);
		m->AddInt("mainHandRate", 0x0C);
		m->AddHref("offHandItem", 0x10);
		m->AddInt("offHandRate", 0x18);
	}
	FORTYPE("dynamicComponents", 0x94, 0x4);
	OpenCon("grades", 0xA4);
	OPENEX("hiddenGeosets", 0xA8)
	{
		FORNOTX("female", 0x4, 0x0C)
		{
			m->AddSource("Item", i);
		}
		FORNOTX("male", 0x14, 0x0C)
		{
			m->AddSource("Item", i);
		}
		FORNOTX("unisex", 0x24, 0x0C)
		{
			m->AddSource("Item", i);
		}
	}
	OPENEX("hiddenLocators", 0xDC)
	{
		FORNOTX("female", 0x4, 0x0C)
		{
			m->AddSource("Item", i);
		}
		FORNOTX("male", 0x14, 0x0C)
		{
			m->AddSource("Item", i);
		}
		FORNOTX("unisex", 0x24, 0x0C)
		{
			m->AddSource("Item", i);
		}
	}
	AddHref("mainHandTrail", 0x110);
	FORCON("objects", 0x118, 0x34)
	{
		m->AddHref("armorScene", 0x4);
		m->AddInt("color", 0x0C);
		m->AddSource("locatorName", 0x10);
		m->AddInt("maskColor", 0x1C);
		m->AddHref("replacement", 0x20);
		m->AddSource("shapeName", 0x28);
	}
	AddHref("pantsTexturePatches", 0x128);
	AddText("sfxMaterial", Enums::GetSfxMaterial(Read(0x130)));
	FORTYPE("staticComponents", 0x134, 0x4);
	AddHref("texturePatches", 0x144);
	AddText("underwear", Enums::GetUnderwear(Read(0x14C)));
	OpenCon("visItemEffects", 0x150);
	OPENEX("visualAliases", 0x154)
	{
		FORCON("visObjectTemplates", 0x4, 0x1C)
		{
			m->AddHref("alias", 0x4);
			m->AddHref("nextAlias", 0x0C);
			m->AddHref("resource", 0x14);
		}
	}
	AddHref("visualItemClass", 0x168);
}