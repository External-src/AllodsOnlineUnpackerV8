#include "Sound3DAction.h"

Sound3DAction::Sound3DAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.Sound3DAction");
	Init();
}

Sound3DAction::~Sound3DAction()
{
}

void Sound3DAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("alias", 0x24);
	AddText("locator", Enums::GetLocatorSlot(Read(0x2C)));
	AddSource("locatorName", 0x30);
	AddSFX("sound", 0x3C);
	AddBool("forcedSoundStop", 0x58);
	AddBool("onlyForMainAvatar", 0x59);
}