#include "CreatureChangeVisItemsAction.h"

CreatureChangeVisItemsAction::CreatureChangeVisItemsAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureChangeVisItemsAction");
	Init();
}

CreatureChangeVisItemsAction::~CreatureChangeVisItemsAction()
{
}

void CreatureChangeVisItemsAction::Init()
{
	AddSource("visActionID", 0x14);
	FORCON("items", 0x24, 0x10)
	{
		m->AddHref("newItem", 0x4);
		m->AddText("slot", Enums::GetSlot(m->Read(0x0C)));
	}
	AddBool("leaveWeapons", 0x34);
	AddBool("notForDolls", 0x35);
	AddBool("removeAllItems", 0x36);
}