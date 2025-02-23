#include "VICVisObjectComponents.h"

VICVisObjectComponents::VICVisObjectComponents(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICVisObjectComponents");
	Init();
}

VICVisObjectComponents::~VICVisObjectComponents()
{
}

void VICVisObjectComponents::Init()
{
	AddText("target", Enums::GetTarget(Read(0x1C)));
	FORTYPE("visObjComponents", 0x20, 0x4);
}