#include "DayTimeComponent.h"

DayTimeComponent::DayTimeComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.DayTimeComponent");
	Init();
}

DayTimeComponent::~DayTimeComponent()
{
}

void DayTimeComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	FORCON("intervals", 0x24, 0x0C)
	{
		m->AddFloat("endTime", 0x4);
		m->AddFloat("startTime", 0x8);
	}
}
