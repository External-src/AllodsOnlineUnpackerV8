#include "CreatureReplaceAnimationsAction.h"

CreatureReplaceAnimationsAction::CreatureReplaceAnimationsAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureReplaceAnimationsAction");
	Init();
}

CreatureReplaceAnimationsAction::~CreatureReplaceAnimationsAction()
{
}

void CreatureReplaceAnimationsAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("member", Enums::GetMember(Read(0x24)));
	OPENEX("onBottom", 0x28)
	{
		FORCONX("animationsReplacements", 0x4, 0x18)
		{
			FORNOTX("forAnimations", 0x4, 0x4)
			{
				m->AddText("Item", Enums::GetAnimation(m->Read(i)));
			}
			m->AddText("play", Enums::GetAnimation(m->Read(0x14)));
		}
		FORNOTX("notReplacedanimations", 0x14, 0x4)
		{
			m->AddText("Item", Enums::GetAnimation(m->Read(i)));
		}
		m->AddBool("skipAnimationIfNoReplacement", 0x24);
	}
	OPENEX("onTop", 0x50)
	{
		FORCONX("animationsReplacements", 0x4, 0x18)
		{
			FORNOTX("forAnimations", 0x4, 0x4)
			{
				m->AddText("Item", Enums::GetAnimation(m->Read(i)));
			}
			m->AddText("play", Enums::GetAnimation(m->Read(0x14)));
		}
		FORNOTX("notReplacedanimations", 0x14, 0x4)
		{
			m->AddText("Item", Enums::GetAnimation(m->Read(i)));
		}
		m->AddBool("skipAnimationIfNoReplacement", 0x24);
	}
	AddHref("priority", 0x78);
	AddText("replaceWhen", Enums::GetReplace(Read(0x80)));
	FORNOT("slots", 0x84, 0x4)
	{
		m->AddText("Item", Enums::GetSlot(m->Read(i)));
	}
	AddBool("restartOnVisualChange", 0x94);
}