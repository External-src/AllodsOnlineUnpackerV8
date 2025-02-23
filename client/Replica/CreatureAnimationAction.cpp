#include "CreatureAnimationAction.h"

CreatureAnimationAction::CreatureAnimationAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureAnimationAction");
	Init();
}

CreatureAnimationAction::~CreatureAnimationAction()
{
}

void CreatureAnimationAction::Init()
{
	AddSource("visActionID", 0x14);
	OPENEX("advanced", 0x24)
	{
		FORCONX("animationKeysAction", 0x4, 0x0C)
		{
			m->OpenCon("action", 0x4);
			m->AddBool("stopIfAnimationStoped", 0x8);
		}
		FORCONX("animationKeysActionPeriod", 0x14, 0x0C)
		{
			m->OpenCon("action", 0x4);
			m->AddBool("stopIfAnimationStoped", 0x8);
		}
		FORCONX("animationKeysSound", 0x24, 0x0C)
		{
			m->OpenCon("action", 0x4);
			m->AddBool("stopIfAnimationStoped", 0x8);
		}
		OPENEX_X("autoHasten", 0x34)
		{
			m->AddText("mode", Enums::GetAutoHasten(m->Read(0x4)));
			m->AddInt("timeToBeLeft", 0x8);
		}
		m->AddText("changeChannelAfterFirstKey", Enums::GetChangeChannel(m->Read(0x40)));
		m->AddText("channelAfterFirstKey", Enums::GetChannel(m->Read(0x44)));
		m->AddText("offendType", Enums::GetOffend(m->Read(0x48)));
		m->AddFloat("speed", 0x4C);
		m->AddText("turnToTarget", Enums::GetTurn(m->Read(0x50)));
		m->AddText("waitRealEvent", Enums::GetWaitEvent(m->Read(0x54)));
		m->AddBool("backgroundAfterFirstKey", 0x58);
		m->AddBool("denyAutoHasten", 0x59);
		m->AddBool("disableRandomFirstFrame", 0x5A);
		m->AddBool("eventPlaybackEnd", 0x5B);
		m->AddBool("skipIfFixedIdleAnimation", 0x5C);
		m->AddBool("stopIfMoved", 0x5D);
		m->AddBool("stopIfRotated", 0x5E);
	}
	FORNOT("animations", 0x84, 0x4)
	{
		m->AddText("Item", Enums::GetAnimation(m->Read(i)));
	}
	AddText("channel", Enums::GetChannel(Read(0x94)));
	AddText("channelOverrideControllers", Enums::GetChannelOverControll(Read(0x98)));
	AddText("channelOverrideMode", Enums::GetOverrideMode(Read(0x9C)));
	OpenCon("channelOverrideScript", 0xA0);
	AddText("mode", Enums::GetAnimMode(Read(0xA4)));
	AddSource("specialController", 0xA8);
	AddText("use", Enums::GetUse(Read(0xB4)));
	AddBool("dontFreezePrecast", 0xB8);
}
