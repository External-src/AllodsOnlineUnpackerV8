#include "AttachCameraSlotComponent.h"

AttachCameraSlotComponent::AttachCameraSlotComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.AttachCameraSlotComponent");
	Init();
}


AttachCameraSlotComponent::~AttachCameraSlotComponent()
{
}

void AttachCameraSlotComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddSource("slotName", 0x24);
}
