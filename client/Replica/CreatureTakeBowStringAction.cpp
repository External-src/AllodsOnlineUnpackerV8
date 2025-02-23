#include "CreatureTakeBowStringAction.h"

CreatureTakeBowStringAction::CreatureTakeBowStringAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureTakeBowStringAction");
	Init();
}

CreatureTakeBowStringAction::~CreatureTakeBowStringAction()
{
}

void CreatureTakeBowStringAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("creatureLocator", Enums::GetLocatorSlot(Read(0x24)));
	AddSource("creatureLocatorName", 0x28);
	AddSource("itemLocatorName", 0x34);
	AddText("itemsSlot", Enums::GetSlot(Read(0x40)));
	AddText("member", Enums::GetMember(Read(0x44)));
}