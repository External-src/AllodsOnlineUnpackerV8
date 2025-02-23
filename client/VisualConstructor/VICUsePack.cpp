#include "VICUsePack.h"

VICUsePack::VICUsePack(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICUsePack");
	Init();
}

VICUsePack::~VICUsePack()
{
}

void VICUsePack::Init()
{

}