#include "VisItemEffectsRanged.h"

VisItemEffectsRanged::VisItemEffectsRanged(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.VisItemEffectsRanged");
	Init();
}

VisItemEffectsRanged::~VisItemEffectsRanged()
{
}

void VisItemEffectsRanged::Init()
{
	AddSource("attachArrowLocatorInItem", 0x18);
	FORNOT("attackAnimation", 0x24, 0x4)
	{
		m->AddText("Item", Enums::GetAnimation(m->Read(i)));
	}
	FORNOT("cheapShotAnimation", 0x34, 0x4)
	{
		m->AddText("Item", Enums::GetAnimation(m->Read(i)));
	}
	FORNOT("cheapShotStartAnimation", 0x44, 0x4)
	{
		m->AddText("Item", Enums::GetAnimation(m->Read(i)));
	}
	AddHref("explosion", 0x54);
	FORCON("holdAnimations", 0x5C, 0x18)
	{
		FORNOTX("animations", 0x4, 0x4)
		{
			m->AddText("Item", Enums::GetAnimation(m->Read(i)));
		}
		m->AddInt("rate", 0x14);
	}
	FORNOT("loadAnimation", 0x6C, 0x4)
	{
		m->AddText("Item", Enums::GetAnimation(m->Read(i)));
	}
	FORCON("loadHoldAnimations", 0x7C, 0x18)
	{
		FORNOTX("animations", 0x4, 0x4)
		{
			m->AddText("Item", Enums::GetAnimation(m->Read(i)));
		}
		m->AddInt("rate", 0x14);
	}
	AddHref("projectile", 0x8C);
	FORNOT("rapidFireAnimation", 0x94, 0x4)
	{
		m->AddText("Item", Enums::GetAnimation(m->Read(i)));
	}
	FORNOT("readyAnimation", 0xA4, 0x4)
	{
		m->AddText("Item", Enums::GetAnimation(m->Read(i)));
	}
	AddText("rotateArrowInItem", Enums::GetRotateArrow(Read(0xB4)));
	AddHref("script", 0xB8);
	AddBool("useTakeStringInHand", 0xC0);
}