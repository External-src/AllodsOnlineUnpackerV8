#include "SingleHitSlot.h"

SingleHitSlot::SingleHitSlot(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.SingleHitSlot");
	Init();
}

SingleHitSlot::~SingleHitSlot()
{
}

void SingleHitSlot::Init()
{
	AddText("slot", Enums::GetSlotShip(Read(0x18)));
}