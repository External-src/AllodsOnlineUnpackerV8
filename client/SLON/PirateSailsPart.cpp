#include "PirateSailsPart.h"

PirateSailsPart::PirateSailsPart(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.PirateSailsPart");
	Init();
}

PirateSailsPart::~PirateSailsPart()
{
}

void PirateSailsPart::Init()
{
	AddHref("item", 0x18);
	AddText("slot", Enums::GetSlotShip(Read(0x20)));
}