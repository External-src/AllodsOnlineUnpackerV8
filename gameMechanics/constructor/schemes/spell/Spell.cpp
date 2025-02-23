#include "Spell.h"

Spell::Spell(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

Spell::~Spell()
{
}

void Spell::Init()
{
	OPENEX("contextActionInfo", 0x1C)
	{
		m->AddTxt("contextDescription", 0x4);
		m->AddHref("contextImage", 0x14);
		m->AddTxt("contextName", 0x1C);
		m->AddInt("priority", 0x2C);
	}
	FORNOT("groups", 0x4C, 0x8)
	{
		m->AddHref("Item", i);
	}
	FORNOT("interruptsActionGroups", 0x5C, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddTxt("Description", 0x70);
	AddTxt("Name", 0x80);
	AddHref("aeMarker", 0x90);
	AddInt("defaultAction", 0x98);
	/*FORCON("descVars", 0x9C, 0x28)
	{
		m->AddSource("name", 0x4);
		m->OpenCon("scaler", 0x10);
		m->AddTxt("text", 0x14);
		m->AddFloat("value", 0x24);
	}*/
	AddHref("durationBuff", 0xAC);
	AddText("element", Enums::GetElement(Read(0xB4)));
	AddText("iffPolicy", Enums::GetiffPolicy(Read(0xB8)));
	AddHref("image", 0xBC);
	AddInt("level", 0xC4);
	OPENEX("mechanics", 0xC8)
	{
		FORTYPEX("casterConditions", 0x4, 0x4);
		FORTYPEX("casterResources", 0x14, 0x4);
		m->OpenCon("channelingMechanics", 0x24);
		FORTYPEX("conditions", 0x28, 0x4);
		m->OpenCon("cooldown", 0x38);
		FORTYPEX("targetConditions", 0x3C, 0x4);
	}
	OpenCon("minRange", 0x114);
	OpenCon("params", 0x118);
	AddInt("prepareDuration", 0x11C);
	OpenCon("range", 0x120);
	FORNOT("ranks", 0x124, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddSource("sysName", 0x134);
	AddText("targetType", Enums::GetTargetType(Read(0x140)));
	AddText("uiSpellBookPageType", Enums::GetuiSpellBookPageType(Read(0x144)));
	OpenCon("useVisScipt", 0x148);
	AddHref("visualScripts", 0x14C);
	AddBool("autoAppendToActionPanel", 0x154);
	AddBool("ignoreGlobalCooldown", 0x155);
	AddBool("isExploit", 0x156);
	AddBool("isHiddenAction", 0x157);
	AddBool("isWorkOnDead", 0x158);
	AddBool("launchWhenReady", 0x159);
	AddBool("needInFront", 0x15A);
	AddBool("replaceLowRanks", 0x15B);
	AddBool("triggersGlobalCooldown", 0x15C);
}