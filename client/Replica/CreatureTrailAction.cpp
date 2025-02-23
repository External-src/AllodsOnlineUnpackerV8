#include "CreatureTrailAction.h"

CreatureTrailAction::CreatureTrailAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureTrailAction");
	Init();
}

CreatureTrailAction::~CreatureTrailAction()
{
}

void CreatureTrailAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("creatureTrail", 0x24);
	AddInt("lengthMSec", 0x2C);
	AddHref("mainHandTrail", 0x30);
	AddBool("useItemsMainHandTrail", 0x40);
}