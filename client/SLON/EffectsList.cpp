#include "EffectsList.h"

EffectsList::EffectsList(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

EffectsList::~EffectsList()
{
}

void EffectsList::Init()
{
	FORCON("effects", 0x18, 0x34)
	{
		m->AddInt("adddedDelay", 0x4);
		m->AddHref("effect", 0x8);
		m->AddInt("fadeInTime", 0x10);
		m->AddInt("fadeOutTime", 0x14);
		m->AddText("locator", Enums::GetLocatorSlot(m->Read(0x18)));
		m->AddSource("locatorName", 0x1C);
		m->AddText("member", Enums::GetMember(m->Read(0x28)));
		m->AddInt("rate", 0x2C);
		m->AddInt("fixPoint", 0x30);
	}
}