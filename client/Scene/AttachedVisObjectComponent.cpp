#include "AttachedVisObjectComponent.h"



AttachedVisObjectComponent::AttachedVisObjectComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Scene.AttachedVisObjectComponent");
	Init();

}


AttachedVisObjectComponent::~AttachedVisObjectComponent()
{
}

void AttachedVisObjectComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddSource("locatorName", 0x24);
	AddVector3("offset", 0x30);
	AddInt("priority", 0x3C);
	AddRotation3("rotation", 0x40);
	AddFloat("scale", 0x50);
	AddHref("visObject", 0x54);
	AddBool("hideWithParentWhenNotAttached", 0x5C);
	AddBool("isPortraitEnabled", 0x5D);
	AddBool("lockScale", 0x5E);
	AddBool("scaleFromGlobal", 0x5F);
	AddBool("skipSound", 0x60);
}
