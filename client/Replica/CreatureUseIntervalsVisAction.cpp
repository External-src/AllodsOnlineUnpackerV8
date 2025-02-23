#include "CreatureUseIntervalsVisAction.h"

CreatureUseIntervalsVisAction::CreatureUseIntervalsVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureUseIntervalsVisAction");
	Init();
}

CreatureUseIntervalsVisAction::~CreatureUseIntervalsVisAction()
{
}

void CreatureUseIntervalsVisAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("intervalVisScript", 0x24);
}