#include "VICCancelDefaultDressSlotSettings.h"

VICCancelDefaultDressSlotSettings::VICCancelDefaultDressSlotSettings(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICCancelDefaultDressSlotSettings");
	Init();
}

VICCancelDefaultDressSlotSettings::~VICCancelDefaultDressSlotSettings()
{
}

void VICCancelDefaultDressSlotSettings::Init()
{
	//null
}