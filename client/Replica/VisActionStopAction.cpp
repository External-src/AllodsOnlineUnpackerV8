#include "VisActionStopAction.h"

VisActionStopAction::VisActionStopAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.VisActionStopAction");
	Init();
}

VisActionStopAction::~VisActionStopAction()
{
}

void VisActionStopAction::Init()
{
	AddSource("visActionID", 0x14);
	AddSource("stoppedActionID", 0x24);
}