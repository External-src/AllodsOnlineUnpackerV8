#include "CreatureChargedSpellAction.h"

CreatureChargedSpellAction::CreatureChargedSpellAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureChargedSpellAction");
	Init();
}

CreatureChargedSpellAction::~CreatureChargedSpellAction()
{
}

void CreatureChargedSpellAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("effectFx", 0x24);
	AddText("effectLocator", Enums::GetLocatorSlot(Read(0x2C)));
	AddInt("fadeInTime", 0x30);
	AddInt("fadeOutTime", 0x34);
}