#include "DelayComponent.h"

DelayComponent::DelayComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Scene.DelayComponent");
	Init();
}

DelayComponent::~DelayComponent()
{
}

void DelayComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	OpenCon("component", 0x24);
	AddFloat("timeMax", 0x28);
	AddFloat("timeMin", 0x2C);
	AddBool("skipLoading", 0x30);
}
