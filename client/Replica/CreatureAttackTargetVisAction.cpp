#include "CreatureAttackTargetVisAction.h"

CreatureAttackTargetVisAction::CreatureAttackTargetVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureAttackTargetVisAction");
	Init();
}

CreatureAttackTargetVisAction::~CreatureAttackTargetVisAction()
{
}

void CreatureAttackTargetVisAction::Init()
{
	AddSource("visActionID", 0x14);
}