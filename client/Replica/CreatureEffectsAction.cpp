#include "CreatureEffectsAction.h"

CreatureEffectsAction::CreatureEffectsAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureEffectsAction");
	Init();
}

CreatureEffectsAction::~CreatureEffectsAction()
{
}

void CreatureEffectsAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("category", Enums::GetCategory(Read(0x24)));
	FORCON("visualEffects", 0x28, 0x7C)
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
		m->AddRotation3("rotation", 0x6C);
		m->AddText("useVisObjectSettings", Enums::GetFrom2(m->Read(0x78)));
	}
	AddBool("restartOnVisCreatureChange", 0x38);
	AddBool("stopOnDeath", 0x39);
}