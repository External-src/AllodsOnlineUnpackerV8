#include "CreatureCancelMountHidingVisAction.h"

CreatureCancelMountHidingVisAction::CreatureCancelMountHidingVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureCancelMountHidingVisAction");
	Init();
}

CreatureCancelMountHidingVisAction::~CreatureCancelMountHidingVisAction()
{
}

void CreatureCancelMountHidingVisAction::Init()
{
	AddSource("visActionID", 0x14);
}