#include "CreatureTakeArrowAction.h"

CreatureTakeArrowAction::CreatureTakeArrowAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureTakeArrowAction");
	Init();
}

CreatureTakeArrowAction::~CreatureTakeArrowAction()
{
}

void CreatureTakeArrowAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("arrow", 0x24);
	AddInt("enchantedArrowIndex", 0x2C);
	AddText("rorate", Enums::GetRotateArrow(Read(0x30)));
	AddBool("forceTakeInHand", 0x34);
}