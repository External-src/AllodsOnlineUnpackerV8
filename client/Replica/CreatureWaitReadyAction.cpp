#include "CreatureWaitReadyAction.h"

CreatureWaitReadyAction::CreatureWaitReadyAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureWaitReadyAction");
	Init();
}

CreatureWaitReadyAction::~CreatureWaitReadyAction()
{
}

void CreatureWaitReadyAction::Init()
{
	AddSource("visActionID", 0x14);
}