#include "CreatureItemAnimationAction.h"

CreatureItemAnimationAction::CreatureItemAnimationAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureItemAnimationAction");
	Init();
}

CreatureItemAnimationAction::~CreatureItemAnimationAction()
{
}

void CreatureItemAnimationAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("animation", Enums::GetAnimation(Read(0x24)));
	AddText("idleAnimation", Enums::GetAnimation(Read(0x28)));
	AddText("itemsSlot", Enums::GetSlot(Read(0x2C)));
	AddText("mode", Enums::GetAnimMode(Read(0x30)));
}