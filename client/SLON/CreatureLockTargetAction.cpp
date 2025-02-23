#include "CreatureLockTargetAction.h"

CreatureLockTargetAction::CreatureLockTargetAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureLockTargetAction");
	Init();
}

CreatureLockTargetAction::~CreatureLockTargetAction()
{
}

void CreatureLockTargetAction::Init()
{
	AddSource("visActionID", 0x14);
	AddFloat("lockTime", 0x24);
}