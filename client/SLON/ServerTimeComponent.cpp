#include "ServerTimeComponent.h"

ServerTimeComponent::ServerTimeComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.ServerTimeComponent");
	Init();
}

ServerTimeComponent::~ServerTimeComponent()
{
}

void ServerTimeComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	OpenCon("component", 0x24);
	FORCON("intervals", 0x28, 0x20)
	{
		AddInt("year", 0x1C);
		AddInt("month", 0x14);
		AddInt("day", 0x4);
		AddInt("hour", 0x0C);
		AddInt("minute", 0x10);
		AddInt("second", 0x18);
		AddFloat("duration", 0x8);
	}
}
