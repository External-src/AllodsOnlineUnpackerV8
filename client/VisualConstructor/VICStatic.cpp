#include "VICStatic.h"

VICStatic::VICStatic(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICStatic");
	Init();
}

VICStatic::~VICStatic()
{
}

void VICStatic::Init()
{
	//null
}