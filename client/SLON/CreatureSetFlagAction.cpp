#include "CreatureSetFlagAction.h"

CreatureSetFlagAction::CreatureSetFlagAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureSetFlagAction");
	Init();
}

CreatureSetFlagAction::~CreatureSetFlagAction()
{
}

void CreatureSetFlagAction::Init()
{
	AddSource("visActionID", 0x14);
	AddSource("flagName", 0x24);
	AddFloat("timeOut", 0x30);
	AddBool("isSet", 0x34);
	AddBool("onlyIfOnMainAvatar", 0x35);
}