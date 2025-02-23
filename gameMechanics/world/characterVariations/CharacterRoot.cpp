#include "CharacterRoot.h"

CharacterRoot::CharacterRoot(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

CharacterRoot::~CharacterRoot()
{
}

void CharacterRoot::Init()
{
	FORNOT("characterTemplates", 0x18, 0x8)
		m->AddHref("Item", i);
	FORCON("factions", 0x28, 0x1C)
	{
		m->AddHref("faction", 0x4);
		FORCONX("races", 0x0C, 0x1C)
		{
			FORCONX("classes", 0x4, 0x1C)
			{
				m->AddHref("raceClass", 0x4);
				FORCONX("sexCharacters", 0x0C, 0x2C)
				{
					m->AddHref("character", 0x4);
					m->AddHref("pet", 0x0C);
					m->AddHref("petMob", 0x14);
					m->AddHref("remortCharacter", 0x1C);
					m->AddHref("visCharacterTemplate", 0x24);
				}
			}
			m->AddHref("race", 0x14);
		}
	}
	FORNOT("sexes", 0x38, 0x8)
		m->AddHref("Item", i);
}