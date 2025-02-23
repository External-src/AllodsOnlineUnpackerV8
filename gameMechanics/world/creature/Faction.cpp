#include "Faction.h"

Faction::Faction(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

Faction::~Faction()
{
}

void Faction::Init()
{
	AddInt("defaultReputation", 0x1C);
	FORNOT("friends", 0x20, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddTxt("name", 0x30);
	AddSource("sysName", 0x40);
	AddBool("hide", 0x4C);
	AddBool("hideNotification", 0x4D);
	AddBool("littleOldMan", 0x4E);
}