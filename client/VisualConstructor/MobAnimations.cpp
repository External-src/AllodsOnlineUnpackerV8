#include "MobAnimations.h"

MobAnimations::MobAnimations(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

MobAnimations::~MobAnimations()
{
}

void MobAnimations::Init()
{
	OPENEX("attack", 0x18)
	{
		FORCONX("animations", 0x4, 0x0C)
		{
			m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
			m->AddInt("rate", 0x8);
		}
		m->AddBool("useAnimations", 0x14);
	}
	OPENEX("attackSwim", 0x30)
	{
		FORCONX("animations", 0x4, 0x0C)
		{
			m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
			m->AddInt("rate", 0x8);
		}
		m->AddBool("useAnimations", 0x14);
	}
	OPENEX("death", 0x48)
	{
		FORCONX("animations", 0x4, 0x0C)
		{
			m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
			m->AddInt("rate", 0x8);
		}
		m->AddBool("useAnimations", 0x14);
	}
	OPENEX("idle", 0x60)
	{
		FORCONX("animations", 0x4, 0x0C)
		{
			m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
			m->AddInt("rate", 0x8);
		}
		m->AddBool("useAnimations", 0x14);
	}
	AddInt("idlePeriodMax", 0x78);
	AddInt("idlePeriodMin", 0x7C);
	OPENEX("idleSwim", 0x80)
	{
		FORCONX("animations", 0x4, 0x0C)
		{
			m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
			m->AddInt("rate", 0x8);
		}
		m->AddBool("useAnimations", 0x14);
	}
	AddInt("idleSwimPeriodMax", 0x98);
	AddInt("idleSwimPeriodMin", 0x9C);
	FORCON("meleeAttackScripts", 0xA0, 0x10)
	{
		m->AddInt("rate", 0x4);
		m->AddHref("script", 0x8);
	}
	FORCON("rangedAttackScripts", 0xB0, 0x10)
	{
		m->AddInt("rate", 0x4);
		m->AddHref("script", 0x8);
	}
	OPENEX("run", 0xC0)
	{
		FORCONX("animations", 0x4, 0x0C)
		{
			m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
			m->AddInt("rate", 0x8);
		}
		m->AddBool("useAnimations", 0x14);
	}
	OPENEX("runInstantAnimations", 0xD8)
	{
		FORCONX("animations", 0x4, 0x0C)
		{
			m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
			m->AddInt("rate", 0x8);
		}
		m->AddBool("useAnimations", 0x14);
	}
	AddInt("runInstantPeriodMax", 0xF0);
	AddInt("runInstantPeriodMin", 0xF4);
	OPENEX("specialIdleParams", 0xF8)
	{
		m->AddInt("beforeStartMax", 0x4);
		m->AddInt("beforeStartMin", 0x8);
		m->AddInt("minTimeAfterIdleJStarts", 0x0C);
		m->AddInt("periodMax", 0x10);
		m->AddInt("periodMin", 0x14);
	}
	OPENEX("swim", 0x110)
	{
		FORCONX("animations", 0x4, 0x0C)
		{
			m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
			m->AddInt("rate", 0x8);
		}
		m->AddBool("useAnimations", 0x14);
	}
	OPENEX("walk", 0x128)
	{
		FORCONX("animations", 0x4, 0x0C)
		{
			m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
			m->AddInt("rate", 0x8);
		}
		m->AddBool("useAnimations", 0x14);
	}
	OPENEX("walkInstantAnimations", 0x140)
	{
		FORCONX("animations", 0x4, 0x0C)
		{
			m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
			m->AddInt("rate", 0x8);
		}
		m->AddBool("useAnimations", 0x14);
	}
	AddInt("walkInstantPeriodMax", 0x158);
	AddInt("walkInstantPeriodMin", 0x15C);
}