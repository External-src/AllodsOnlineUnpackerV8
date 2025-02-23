#include "VICHideUnderwear.h"

VICHideUnderwear::VICHideUnderwear(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICHideUnderwear");
	Init();
}

VICHideUnderwear::~VICHideUnderwear()
{
}

void VICHideUnderwear::Init()
{
	//null
}