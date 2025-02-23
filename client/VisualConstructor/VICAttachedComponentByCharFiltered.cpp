#include "VICAttachedComponentByCharFiltered.h"

VICAttachedComponentByCharFiltered::VICAttachedComponentByCharFiltered(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICAttachedComponentByCharFiltered");
	Init();
}

VICAttachedComponentByCharFiltered::~VICAttachedComponentByCharFiltered()
{
}

void VICAttachedComponentByCharFiltered::Init()
{
	FORCON("cases", 0x18, 0x24)
	{
		m->AddSource("filter", 0x4);
		m->AddHref("replacement", 0x10);
		m->AddHref("visCharacterTemplate", 0x18);
		m->OpenCon("visObjComponent", 0x20);
	}
}