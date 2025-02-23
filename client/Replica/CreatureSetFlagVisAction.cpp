#include "CreatureSetFlagVisAction.h"

CreatureSetFlagVisAction::CreatureSetFlagVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureSetFlagVisAction");
	Init();
}

CreatureSetFlagVisAction::~CreatureSetFlagVisAction()
{
}

void CreatureSetFlagVisAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("visualFlag", 0x24);
	AddBool("mainAvatarOnly", 0x2C);
}