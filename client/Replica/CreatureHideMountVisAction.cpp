#include "CreatureHideMountVisAction.h"

CreatureHideMountVisAction::CreatureHideMountVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureHideMountVisAction");
	Init();
}

CreatureHideMountVisAction::~CreatureHideMountVisAction()
{
}

void CreatureHideMountVisAction::Init()
{
	AddSource("visActionID", 0x14);
}