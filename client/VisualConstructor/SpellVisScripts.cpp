#include "SpellVisScripts.h"

SpellVisScripts::SpellVisScripts(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

SpellVisScripts::~SpellVisScripts()
{
}

void SpellVisScripts::Init()
{
	AddTxt("Description", 0x18);
	OpenCon("actionBarCancel", 0x28);
	OpenCon("actionBarComplite", 0x2C);
	OpenCon("actionBarStart", 0x30);
	AddText("precastType", Enums::GetPrecastType(Read(0x34)));
	OpenCon("wholeCasting", 0x38);
	OpenCon("charged", 0x40);
	OpenCon("launch", 0x44);
	OPENEX("ownKillingParams", 0x48)
	{
		m->AddFloat("probabilityNoOverkill", 0x4);
		m->AddFloat("probabilityWithOverkill", 0x8);
	}
	OPENEX("playOnTargets", 0x54)
	{
		m->OpenCon("specialAction", 0x4);
		m->AddBool("skipBloodFx", 0x8);
		m->AddBool("skipHitAnimations", 0x9);
	}
	AddBool("useOwnKillingParams", 0x60);
}