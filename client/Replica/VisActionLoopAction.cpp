#include "VisActionLoopAction.h"

VisActionLoopAction::VisActionLoopAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.VisActionLoopAction");
	Init();
}

VisActionLoopAction::~VisActionLoopAction()
{
}

void VisActionLoopAction::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("actionToLoop", 0x24);
	AddInt("repeat", 0x28);
	AddFloat("totalTime", 0x2C);
}