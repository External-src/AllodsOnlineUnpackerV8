#include "Character.h"

Character::Character(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

Character::~Character()
{
}

void Character::Init()
{
	AddHref("characterRaceClass", 0x18);
	AddHref("characterSex", 0x20);
	AddHref("characterType", 0x28);
	FORCON("dressItems", 0x30, 0x10)
	{
		m->AddHref("item", 0x4);
		m->AddText("slot", Enums::GetSlot(m->Read(0x0C)));
	}
	FORCON("growths", 0x40, 0x74)
	{
		m->AddSource("chargenAnimationLoop", 0x4);
		m->AddSource("chargenAnimationNewEquipment", 0x10);
		m->AddSource("chargenAnimationStart", 0x1C);
		FORCONX("chargenDressedItems", 0x28, 0x10)
		{
			m->AddHref("item", 0x4);
			m->AddText("slot", Enums::GetSlot(m->Read(0x0C)));
		}
		FORCONX("chargenEffects", 0x38, 0x20)
		{
			m->AddSource("locator", 0x4);
			m->AddText("runType", Enums::GetChargenEffect(m->Read(0x10)));
			m->AddFloat("scale", 0x14);
			m->AddHref("visObj", 0x18);
		}
		m->AddInt("level", 0x48);
		OPENEX_X("mount", 0x4C)
		{
			m->AddSource("chargenAnimationLoop", 0x4);
			m->AddSource("chargenAnimationStart", 0x10);
			m->AddFloat("scale", 0x1C);
			m->AddHref("visualMount", 0x20);
		}
	}
}