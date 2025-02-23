#include "CreatureSayAction.h"

CreatureSayAction::CreatureSayAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureSayAction");
	Init();
}

CreatureSayAction::~CreatureSayAction()
{
}

void CreatureSayAction::Init()
{
	AddSource("visActionID", 0x14);
	AddTxt("text", 0x24);
}