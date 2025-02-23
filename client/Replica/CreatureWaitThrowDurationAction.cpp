#include "CreatureWaitThrowDurationAction.h"

CreatureWaitThrowDurationAction::CreatureWaitThrowDurationAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureWaitThrowDurationAction");
	Init();
}

CreatureWaitThrowDurationAction::~CreatureWaitThrowDurationAction()
{
}

void CreatureWaitThrowDurationAction::Init()
{
	AddSource("visActionID", 0x14);
	AddInt("delayTime", 0x24);
}