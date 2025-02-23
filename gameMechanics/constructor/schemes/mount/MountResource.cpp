#include "MountResource.h"

MountResource::MountResource(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

MountResource::~MountResource()
{
}

void MountResource::Init()
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
	AddTxt("Name", 0x70);
	FORNOT("abilities", 0x80, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddHref("alternativeSkins", 0x90);
	AddHref("basicSkin", 0x98);
	FORNOT("contextActions", 0xA0, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddFloat("corpulence", 0xB0);
	AddTxt("description", 0xB4);
	AddInt("grade", 0xC4);
	OPENEX("mechanics", 0xC8)
	{
		m->AddFloat("health", 0x4);
		m->AddFloat("healthDelta", 0x8);
		m->AddInt("healthLevelDelta", 0x0C);
		m->AddInt("prepareDuration", 0x10);
		m->AddInt("prepareDurationDelta", 0x14);
		m->AddFloat("regen", 0x18);
		m->AddFloat("speed", 0x1C);
		m->AddFloat("speedDelta", 0x20);
	}
	FORNOT("overrideMounts", 0xEC, 0x8)
	{
		m->AddHref("Item", i);
	}
	OpenCon("penaltyCalcer", 0xFC);
	FORNOT("spells", 0x100, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddSource("sysName", 0x110);
	OPENEX("timeLeft", 0x11C)
	{
		m->AddInt("day", 0x4);
		m->AddInt("hour", 0x8);
		m->AddInt("minute", 0x0C);
		m->AddInt("second", 0x14);
		m->AddInt("ms", 0x10);
	}
	AddBool("canBeMorphed", 0x134);
	AddBool("isExoMount", 0x135);
	AddBool("isProbe", 0x136);
}