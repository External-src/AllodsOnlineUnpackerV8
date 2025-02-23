#include "LooterEmoteAction.h"

LooterEmoteAction::LooterEmoteAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.LooterEmoteAction");
	Init();
}

LooterEmoteAction::~LooterEmoteAction()
{
}

void LooterEmoteAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("animateEmote", Enums::GetAnimation(Read(0x24)));
	AddFloat("fadeInTime", 0x28);
	AddFloat("fadeOutTime", 0x2C);
	AddText("mode", Enums::GetAnimMode(Read(0x30)));
	AddBool("playWhileLooting", 0x34);
}