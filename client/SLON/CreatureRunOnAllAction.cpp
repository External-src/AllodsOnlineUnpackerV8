#include "CreatureRunOnAllAction.h"

CreatureRunOnAllAction::CreatureRunOnAllAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureRunOnAllAction");
	Init();
}

CreatureRunOnAllAction::~CreatureRunOnAllAction()
{
}

void CreatureRunOnAllAction::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("actionToPlay", 0x24);
	AddBool("onlyIfOnMainAvatar", 0x28);
	AddBool("playOnAvatar", 0x29);
}