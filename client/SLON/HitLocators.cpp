#include "HitLocators.h"

HitLocators::HitLocators(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.HitLocators");
	Init();
}

HitLocators::~HitLocators()
{
}

void HitLocators::Init()
{
	FORNOT("hitLocators", 0x18, 0x0C)
	{
		m->AddVector3("Item", i);
	}
}