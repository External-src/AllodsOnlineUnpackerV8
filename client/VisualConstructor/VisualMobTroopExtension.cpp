#include "VisualMobTroopExtension.h"

VisualMobTroopExtension::VisualMobTroopExtension(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VisualMobTroopExtension");
	Init();
}

VisualMobTroopExtension::~VisualMobTroopExtension()
{
}

void VisualMobTroopExtension::Init()
{
	FORCON("members", 0x18, 0x68)
	{
		m->AddHref("character", 0x4);
		OPENEX_X("variation", 0x0C)
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
	}
}
