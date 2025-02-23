#include "CharacterVariations.h"

CharacterVariations::CharacterVariations(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

CharacterVariations::~CharacterVariations()
{
}

void CharacterVariations::Init()
{
	FORNOT("additional", 0x18, 0x8)
	{
		m->AddHref("Item", i);
	}
	OPENEX("defaultVariation", 0x28)
	{
		m->AddHref("additionalVariation", 0x4);
		m->AddHref("face", 0x0C);
		m->AddHref("facial", 0x14);
		m->AddInt("hairColor", 0x1C);
		m->AddHref("hairGeoset", 0x20);
		OPENEX_X("morphPreset", 0x28)
		{
			FORCONX("values", 0x8, 0x10)
			{
				m->AddText("controlName", Enums::GetControlName(m->Read(0x8)));
				m->AddFloat("value", 0x0C);
			}
		}
		m->AddInt("morphPresetIndex", 0x40);
		m->AddHref("shoulderStone", 0x44);
		m->AddInt("shoulderStoneColor", 0x4C);
		m->AddHref("skin", 0x50);
		m->AddInt("skinColor", 0x58);
	}
	FORNOT("faces", 0x84, 0x8)
	{
		m->AddHref("Item", i);
	}
	FORNOT("facial", 0x94, 0x8)
	{
		m->AddHref("Item", i);
	}
	FORNOT("hair", 0xA4, 0x8)
	{
		m->AddHref("Item", i);
	}
	FORNOT("hairColors", 0xB4, 0x4)
	{
		m->AddInt("Item", i);
	}
	FORNOT("mainTextures", 0xC4, 0x8)
	{
		m->AddHref("Item", i);
	}
	FORNOT("shoulderStoneColors", 0xD4, 0x4)
	{
		m->AddInt("Item", i);
	}
	FORNOT("shoulderStones", 0xE4, 0x8)
	{
		m->AddHref("Item", i);
	}
	FORNOT("skinColors", 0xF4, 0x4)
	{
		m->AddInt("Item", i);
	}
	AddBool("ignoreHairColor", 0x104);
}