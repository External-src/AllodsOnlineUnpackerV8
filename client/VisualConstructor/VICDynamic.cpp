#include "VICDynamic.h"

VICDynamic::VICDynamic(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICDynamic");
	Init();
}

VICDynamic::~VICDynamic()
{
}

void VICDynamic::Init()
{
	//null
}