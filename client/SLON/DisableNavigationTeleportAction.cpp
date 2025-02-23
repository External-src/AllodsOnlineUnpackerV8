#include "DisableNavigationTeleportAction.h"

DisableNavigationTeleportAction::DisableNavigationTeleportAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.DisableNavigationTeleportAction");
	Init();
}

DisableNavigationTeleportAction::~DisableNavigationTeleportAction()
{
}

void DisableNavigationTeleportAction::Init()
{
	AddSource("visActionID", 0x14);
}