#include "VICHideAttachedObj.h"

VICHideAttachedObj::VICHideAttachedObj(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICHideAttachedObj");
	Init();
}

VICHideAttachedObj::~VICHideAttachedObj()
{
}

void VICHideAttachedObj::Init()
{
	AddHref("attachedObj", 0x18);
	AddSource("locatorName", 0x20);
	AddBool("hideEachFrame", 0x2C);
}