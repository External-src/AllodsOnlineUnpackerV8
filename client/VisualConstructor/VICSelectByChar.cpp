#include "VICSelectByChar.h"

VICSelectByChar::VICSelectByChar(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICSelectByChar");
	Init();
}

VICSelectByChar::~VICSelectByChar()
{
}

void VICSelectByChar::Init()
{
	//throw(EXCEPTION_ACCESS_VIOLATION);
	//null
}