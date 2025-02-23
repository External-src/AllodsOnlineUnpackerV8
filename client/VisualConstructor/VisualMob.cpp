#include "VisualMob.h"

VisualMob::VisualMob(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\" "));
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

VisualMob::~VisualMob()
{
}

void VisualMob::Init()
{
	AddHref("character", 0x18);
	OPENEX("colorCoefficients", 0x20)
	{
		m->AddFloat("b", 0x4);
		m->AddFloat("g", 0x8);
		m->AddFloat("r", 0x0C);
		m->AddFloat("w", 0x10);
		m->AddBool("use", 0x14);
	}
	OPENEX("creatureParameters", 0x38)
	{
		m->AddBool("disableProceduralAndColorEffects", 0x4);
	}
	AddFloat("decalScale", 0x40);
	AddText("fixedIdleAnimation", Enums::GetAnimation(Read(0x44)));
	AddInt("hitAnimationCooldown", 0x48);
	AddInt("hitCritAnimationCooldown", 0x4C);
	FORCON("items", 0x50, 0x10)
	{
		m->AddHref("item", 0x4);
		m->AddText("slot", Enums::GetSlot(m->Read(0xC)));
	}
	AddHref("mobAnimations", 0x60);
	AddHref("mobEventsScripts", 0x68);
	OpenCon("mobExtension", 0x70);
	AddAABB("pickAabb", 0x74);
	AddFloat("procedureFxScale", 0x8C);
	AddFloat("scale", 0x90);
	AddHref("sfxArmorSet", 0x94);
	AddHref("soundVariation", 0x9C);
	AddInt("timeToCorpseFadingMax", 0xA4);
	AddInt("timeToCorpseFadingMin", 0xA8);
	AddFloat("transparency", 0xAC);
	OPENEX("variation", 0xB0)
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
	OpenCon("visualScript", 0x10C);
	FORNOT("visualStates", 0x110, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddBool("disableFall", 0x120);
	AddBool("skipCharacterVisualScript", 0x121);
	AddBool("useIdleSpecial", 0x122);
	AddBool("useVisualTweaks", 0x123);
}
