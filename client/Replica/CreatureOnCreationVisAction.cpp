#include "CreatureOnCreationVisAction.h"

CreatureOnCreationVisAction::CreatureOnCreationVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureOnCreationVisAction");
	Init();
}

CreatureOnCreationVisAction::~CreatureOnCreationVisAction()
{
}

void CreatureOnCreationVisAction::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("visualScript", 0x24);
	AddBool("skipTransparencyFading", 0x28);
}