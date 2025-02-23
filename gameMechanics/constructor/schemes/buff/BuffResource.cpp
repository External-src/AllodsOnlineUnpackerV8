#include "BuffResource.h"

BuffResource::BuffResource(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

BuffResource::~BuffResource()
{
}

void BuffResource::Init()
{
	AddTxt("Description", 0x1C);
	AddTxt("Name", 0x2C);
	OpenCon("actionOnVisualChange", 0x3C);
	FORCON("descVars", 0x40, 0x28)
	{
		m->AddSource("name", 0x4);
		m->OpenCon("scaler", 0x10);
		m->AddTxt("text", 0x14);
		m->AddFloat("value", 0x24);
	}
	FORNOT("gainSpells", 0x50, 0x8)
	{
		m->AddHref("Item", i);
	}
	FORNOT("groups", 0x60, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddHref("image", 0x70);
	FORNOT("ranks", 0x78, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddTxt("shortName", 0x88);
	AddInt("stackLimit", 0x98);
	AddSource("sysUIScriptName", 0x9C);
	FORNOT("uiComponents", 0xA8, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddHref("visScript", 0xB8);
	FORCON("visualEffects", 0xC0, 0x7C)
	{
		m->AddInt("delay", 0x4);
		m->AddHref("effectAlias", 0x8);
		OPENEX_X("effectAnimations", 0x10)
		{
			FORNOTX("animations", 0x4, 0x4)
			{
				m->AddText("Item", Enums::GetAnimation(m->Read(i)));
			}
			m->AddText("mode", Enums::GetAnimMode(m->Read(0x14)));
		}
		m->AddHref("effectFx", 0x28);
		m->AddInt("fadeInTime", 0x30);
		m->AddInt("fadeOutTime", 0x34);
		m->AddFloat("scale", 0x38);
		m->AddBool("fixPoint", 0x3C);
		m->AddBool("lockScale", 0x3D);
		m->AddBool("muteFxSounds", 0x3E);
		m->AddBool("ignoreParentRotation", 0x44);
		m->AddText("locator", Enums::GetLocatorSlot(m->Read(0x48)));
		m->AddSource("locatorName", 0x4C);
		m->AddText("member", Enums::GetMember(m->Read(0x58)));
		m->OpenCon("offendTime", 0x5C);
		m->AddVector3("offset", 0x60);
		m->AddVector3("rotation", 0x6C);
		m->AddText("useVisObjectSettings", Enums::GetVisObjectSettings(m->Read(0x78)));
	}
	FORCON("visualEffectsDecCount", 0xD0, 0x7C)
	{
		m->AddInt("delay", 0x4);
		m->AddHref("effectAlias", 0x8);
		OPENEX_X("effectAnimations", 0x10)
		{
			FORNOTX("animations", 0x4, 0x4)
			{
				m->AddText("Item", Enums::GetAnimation(m->Read(i)));
			}
			m->AddText("mode", Enums::GetAnimMode(m->Read(0x14)));
		}
		m->AddHref("effectFx", 0x28);
		m->AddInt("fadeInTime", 0x30);
		m->AddInt("fadeOutTime", 0x34);
		m->AddFloat("scale", 0x38);
		m->AddBool("fixPoint", 0x3C);
		m->AddBool("lockScale", 0x3D);
		m->AddBool("muteFxSounds", 0x3E);
		m->AddBool("ignoreParentRotation", 0x44);
		m->AddText("locator", Enums::GetLocatorSlot(m->Read(0x48)));
		m->AddSource("locatorName", 0x4C);
		m->AddText("member", Enums::GetMember(m->Read(0x58)));
		m->OpenCon("offendTime", 0x5C);
		m->AddVector3("offset", 0x60);
		m->AddVector3("rotation", 0x6C);
		m->AddText("useVisObjectSettings", Enums::GetVisObjectSettings(m->Read(0x78)));
	}
	FORCON("visualEffectsIncCount", 0xE0, 0x7C)
	{
		m->AddInt("delay", 0x4);
		m->AddHref("effectAlias", 0x8);
		OPENEX_X("effectAnimations", 0x10)
		{
			FORNOTX("animations", 0x4, 0x4)
			{
				m->AddText("Item", Enums::GetAnimation(m->Read(i)));
			}
			m->AddText("mode", Enums::GetAnimMode(m->Read(0x14)));
		}
		m->AddHref("effectFx", 0x28);
		m->AddInt("fadeInTime", 0x30);
		m->AddInt("fadeOutTime", 0x34);
		m->AddFloat("scale", 0x38);
		m->AddBool("fixPoint", 0x3C);
		m->AddBool("lockScale", 0x3D);
		m->AddBool("muteFxSounds", 0x3E);
		m->AddBool("ignoreParentRotation", 0x44);
		m->AddText("locator", Enums::GetLocatorSlot(m->Read(0x48)));
		m->AddSource("locatorName", 0x4C);
		m->AddText("member", Enums::GetMember(m->Read(0x58)));
		m->OpenCon("offendTime", 0x5C);
		m->AddVector3("offset", 0x60);
		m->AddVector3("rotation", 0x6C);
		m->AddText("useVisObjectSettings", Enums::GetVisObjectSettings(m->Read(0x78)));
	}
	FORCON("visualPostEffects", 0xF0, 0x7C)
	{
		m->AddInt("delay", 0x4);
		m->AddHref("effectAlias", 0x8);
		OPENEX_X("effectAnimations", 0x10)
		{
			FORNOTX("animations", 0x4, 0x4)
			{
				m->AddText("Item", Enums::GetAnimation(m->Read(i)));
			}
			m->AddText("mode", Enums::GetAnimMode(m->Read(0x14)));
		}
		m->AddHref("effectFx", 0x28);
		m->AddInt("fadeInTime", 0x30);
		m->AddInt("fadeOutTime", 0x34);
		m->AddFloat("scale", 0x38);
		m->AddBool("fixPoint", 0x3C);
		m->AddBool("lockScale", 0x3D);
		m->AddBool("muteFxSounds", 0x3E);
		m->AddBool("ignoreParentRotation", 0x44);
		m->AddText("locator", Enums::GetLocatorSlot(m->Read(0x48)));
		m->AddSource("locatorName", 0x4C);
		m->AddText("member", Enums::GetMember(m->Read(0x58)));
		m->OpenCon("offendTime", 0x5C);
		m->AddVector3("offset", 0x60);
		m->AddVector3("rotation", 0x6C);
		m->AddText("useVisObjectSettings", Enums::GetVisObjectSettings(m->Read(0x78)));
	}
	AddBool("interfaceHighPriority", 0x100);
	AddBool("isDetachableOnWill", 0x101);
	AddBool("isGradual", 0x102);
	AddBool("isHelpful", 0x103);
	AddBool("isLongTimeLifeBuff", 0x104);
	AddBool("isMultiple", 0x105);
	AddBool("isStackable", 0x106);
	AddBool("needVisualize", 0x107);
	AddBool("needVisualizeDuration", 0x108);
	AddBool("onlyForTargetAndCaster", 0x109);
	AddBool("restartOnVisualChange", 0x10A);
}