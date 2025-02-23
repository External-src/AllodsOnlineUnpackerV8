#include "VICSelectComponentByRankInGuild.h"

VICSelectComponentByRankInGuild::VICSelectComponentByRankInGuild(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICSelectComponentByRankInGuild");
	Init();
}

VICSelectComponentByRankInGuild::~VICSelectComponentByRankInGuild()
{
}

void VICSelectComponentByRankInGuild::Init()
{
	FORCON("cases", 0x18, 0x2C)
	{
		FORTYPEX("dynamicComponents", 0x4, 0x4);
		m->AddInt("maxValue", 0x14);
		m->AddInt("minValue", 0x18);
		FORTYPEX("staticComponents", 0x1C, 0x4);
	}
}