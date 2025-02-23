#include "VisObjectTemplate.h"

VisObjectTemplate::VisObjectTemplate(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\" "));
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

VisObjectTemplate::~VisObjectTemplate()
{
}

void VisObjectTemplate::Init()
{
	OPENEX("defaultState", 0x18)
	{
		FORCONX("keySounds", 0x4, 0x14)
		{
			FORCONX("tunedSounds", 0x4, 0x2C)
			{
				m->AddFloat("pitch", 0x4);
				m->AddSFX("sound", 0x8);
				m->AddFloat("volume", 0x24);
				m->AddBool("overrideMoveSFX", 0x28);
			}
		}
		FORCONX("objects", 0x14, 0x18)
		{
			m->AddSource("locatorName", 0x4);
			m->AddHref("visObject", 0x10);
		}
		m->AddSFX("sound", 0x24);
		m->AddBool("allowMultipleSoundInstances", 0x40);
		m->AddBool("playSoundOnKeys", 0x41);
		m->AddHref("animation", 0x48);
		m->AddBool("isNecessaryAnim", 0x50);
	}
	AddInt("fadeInMS", 0x6C);
	AddInt("fadeOutMS", 0x70);
	AddHref("geometry", 0x74);
	AddHref("particle", 0x7C);
	AddHref("questHighlight", 0x84);
	AddFloat("replaceDistance", 0x8C);
	AddHref("replacement", 0x90);
	AddFloat("scale", 0x98);
	AddSFX("sound", 0x9C);
	FORCON("states", 0xB8, 0x54)
	{
		FORCONX("keySounds", 0x4, 0x14)
		{
			FORCONX("tunedSounds", 0x4, 0x2C)
			{
				m->AddFloat("pitch", 0x4);
				m->AddSFX("sound", 0x8);
				m->AddFloat("volume", 0x24);
				m->AddBool("overrideMoveSFX", 0x28);
			}
		}
		FORCONX("objects", 0x14, 0x18)
		{
			m->AddSource("locatorName", 0x4);
			m->AddHref("visObject", 0x10);
		}
		m->AddSFX("sound", 0x24);
		m->AddBool("allowMultipleSoundInstances", 0x40);
		m->AddBool("playSoundOnKeys", 0x41);
		m->AddHref("animation", 0x48);
		m->AddBool("isNecessaryAnim", 0x50);
	}
	FORNOT("visObjComponents", 0xC8, 0x4)
	{
		m->OpenCon("Item", i);
	}
	AddBool("softReplace", 0xD8);
}
