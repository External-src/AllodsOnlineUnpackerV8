#include "CreatureSetPortraitAction.h"

CreatureSetPortraitAction::CreatureSetPortraitAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureSetPortraitAction");
	Init();
}

CreatureSetPortraitAction::~CreatureSetPortraitAction()
{
}

void CreatureSetPortraitAction::Init()
{
	AddSource("visActionID", 0x14);
	AddSource("portraitName", 0x24);
	AddBool("onlyIfOnMainAvatar", 0x30);
}