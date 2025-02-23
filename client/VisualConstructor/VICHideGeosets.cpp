#include "VICHideGeosets.h"

VICHideGeosets::VICHideGeosets(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICHideGeosets");
	Init();
}

VICHideGeosets::~VICHideGeosets()
{
}

void VICHideGeosets::Init()
{
	//null
}