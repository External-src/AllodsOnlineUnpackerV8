#include "ShipProximityChecker.h"

ShipProximityChecker::ShipProximityChecker(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.ShipProximityChecker");
	Init();
}

ShipProximityChecker::~ShipProximityChecker()
{
}

void ShipProximityChecker::Init()
{
	AddFloat("endRadius", 0x18);
	AddFloat("maxTransparency", 0x1C);
	AddFloat("startRadius", 0x20);
}