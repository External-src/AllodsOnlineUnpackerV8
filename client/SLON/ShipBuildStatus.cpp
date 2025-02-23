#include "ShipBuildStatus.h"

ShipBuildStatus::ShipBuildStatus(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.ShipBuildStatus");
	Init();
}

ShipBuildStatus::~ShipBuildStatus()
{
}

void ShipBuildStatus::Init()
{
	AddHref("settings", 0x18);
}