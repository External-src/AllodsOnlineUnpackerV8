#include "ShakeAction.h"

ShakeAction::ShakeAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.ShakeAction");
	Init();
}

ShakeAction::~ShakeAction()
{
}

void ShakeAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("params", 0x24);
}