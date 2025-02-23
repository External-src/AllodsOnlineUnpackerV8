#include "Sound2DAction.h"

Sound2DAction::Sound2DAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.Sound2DAction");
	Init();
}

Sound2DAction::~Sound2DAction()
{
}

void Sound2DAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("actionType", Enums::GetActionType(Read(0x24)));
	AddFloat("musicSourceMaxRadius", 0x28);
	FORCON("musicSourceParameters", 0x2C, 0x10)
	{
		m->AddHref("parameter", 0x4);
		m->AddFloat("value", 0x0C);
	}
	AddSFX2("reverbPreset", 0x3C);
	AddSFX2("sound", 0x54);
	AddBool("forcedSoundStop", 0x6C);
	AddBool("onlyForMainAvatar", 0x6D);
	AddBool("resetGlobalParamsOnStop", 0x6E);
}