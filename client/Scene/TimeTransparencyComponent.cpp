#include "TimeTransparencyComponent.h"

TimeTransparencyComponent::TimeTransparencyComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Scene.TimeTransparencyComponent");
	Init();
}

TimeTransparencyComponent::~TimeTransparencyComponent()
{
}

void TimeTransparencyComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddFloat("durationFrom", 0x24);
	AddFloat("durationTo", 0x28);
	AddFloat("fadeAlpha", 0x2C);
	AddFloat("fadeTime", 0x30);
	AddFloat("timeStartFrom", 0x34);
	AddFloat("timeStartTo", 0x38);
}
