#include "MimicSlotPart.h"

MimicSlotPart::MimicSlotPart(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.MimicSlotPart");
	Init();
}

MimicSlotPart::~MimicSlotPart()
{
}

void MimicSlotPart::Init()
{
}