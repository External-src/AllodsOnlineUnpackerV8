#include "CreatureParalyzeAction.h"

CreatureParalyzeAction::CreatureParalyzeAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureParalyzeAction");
	Init();
}

CreatureParalyzeAction::~CreatureParalyzeAction()
{
}

void CreatureParalyzeAction::Init()
{
	AddSource("visActionID", 0x14);
}