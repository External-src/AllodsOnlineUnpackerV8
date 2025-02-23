#include "WeatherVisObjComponent.h"

WeatherVisObjComponent::WeatherVisObjComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Map.WeatherVisObjComponent");
	Init();
}

WeatherVisObjComponent::~WeatherVisObjComponent()
{
}

void WeatherVisObjComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddHref("weatherType", 0x24);
}
