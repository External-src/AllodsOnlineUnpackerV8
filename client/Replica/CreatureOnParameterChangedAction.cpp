#include "CreatureOnParameterChangedAction.h"

CreatureOnParameterChangedAction::CreatureOnParameterChangedAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureOnParameterChangedAction");
	Init();
}

CreatureOnParameterChangedAction::~CreatureOnParameterChangedAction()
{
}

void CreatureOnParameterChangedAction::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("parameter", 0x24);
	OpenCon("parameterDownScript", 0x28);
	OpenCon("parameterUpScript", 0x2C);
}