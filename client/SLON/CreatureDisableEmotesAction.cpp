#include "CreatureDisableEmotesAction.h"

CreatureDisableEmotesAction::CreatureDisableEmotesAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureDisableEmotesAction");
	Init();
}

CreatureDisableEmotesAction::~CreatureDisableEmotesAction()
{
}

void CreatureDisableEmotesAction::Init()
{
	AddSource("visActionID", 0x14);
}