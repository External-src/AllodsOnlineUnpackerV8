#include "CreatureIfFlagVisAction.h"

CreatureIfFlagVisAction::CreatureIfFlagVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureIfFlagVisAction");
	Init();
}

CreatureIfFlagVisAction::~CreatureIfFlagVisAction()
{
}

void CreatureIfFlagVisAction::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("visScriptEnd", 0x24);
	OpenCon("visScriptLoop", 0x28);
	OpenCon("visScriptStart", 0x2C);
	AddHref("visualFlag", 0x30);
}