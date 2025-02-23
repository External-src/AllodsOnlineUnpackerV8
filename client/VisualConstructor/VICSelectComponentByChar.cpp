#include "VICSelectComponentByChar.h"

VICSelectComponentByChar::VICSelectComponentByChar(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICSelectComponentByChar");
	Init();
}

VICSelectComponentByChar::~VICSelectComponentByChar()
{
}

void VICSelectComponentByChar::Init()
{
	FORCON("cases", 0x18, 0x14)
	{
		m->OpenCon("dynamicComponent", 0x4);
		m->OpenCon("staticComponent", 0x8);
		m->AddHref("visCharacterTemplate", 0x0C);
	}
}