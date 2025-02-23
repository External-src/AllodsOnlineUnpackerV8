#include "StopVisObjectComponents.h"

StopVisObjectComponents::StopVisObjectComponents(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Scene.StopVisObjectComponents");
	Init();
}

StopVisObjectComponents::~StopVisObjectComponents()
{
}

void StopVisObjectComponents::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	FORNOT("stopedComponentIDs", 0x24, 0x0C)
	{
		m->AddSource("Item", i);
	}
}
