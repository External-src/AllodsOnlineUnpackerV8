#include "CreatureGridViewAction.h"

CreatureGridViewAction::CreatureGridViewAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureGridViewAction");
	Init();
}

CreatureGridViewAction::~CreatureGridViewAction()
{
}

void CreatureGridViewAction::Init()
{
	AddSource("visActionID", 0x14);
	AddBool("onlyIfOnMainAvatar", 0x24);
}