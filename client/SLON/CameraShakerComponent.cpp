#include "CameraShakerComponent.h"



CameraShakerComponent::CameraShakerComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CameraShakerComponent");
	Init();
}


CameraShakerComponent::~CameraShakerComponent()
{
}

void CameraShakerComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddHref("params", 0x24);
}
