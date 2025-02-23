#include "CreatureForceMoveAction.h"

CreatureForceMoveAction::CreatureForceMoveAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureForceMoveAction");
	Init();
}

CreatureForceMoveAction::~CreatureForceMoveAction()
{
}

void CreatureForceMoveAction::Init()
{
	AddSource("visActionID", 0x14);
	AddFloat("forceCoeff", 0x24);
}