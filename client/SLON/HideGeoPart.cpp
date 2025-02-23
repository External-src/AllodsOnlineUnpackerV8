#include "HideGeoPart.h"

HideGeoPart::HideGeoPart(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.HideGeoPart");
	Init();
}

HideGeoPart::~HideGeoPart()
{
}

void HideGeoPart::Init()
{
	FORNOT("hiddenGeosets", 0x18, 0x0C)
	{
		m->AddSource("Item", i);
	}
}