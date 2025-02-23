#include "CreatureHoldWeaponAction.h"

CreatureHoldWeaponAction::CreatureHoldWeaponAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureHoldWeaponAction");
	Init();
}

CreatureHoldWeaponAction::~CreatureHoldWeaponAction()
{
}

void CreatureHoldWeaponAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("hold", Enums::GetHold(Read(0x24)));
	AddFloat("time", 0x28);
	AddBool("boast", 0x2C);
}