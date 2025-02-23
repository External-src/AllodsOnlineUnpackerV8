#include "VisObjComponentsFile.h"

VisObjComponentsFile::VisObjComponentsFile(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Scene.VisObjComponentsFile");
	Init();
}

VisObjComponentsFile::~VisObjComponentsFile()
{
}

void VisObjComponentsFile::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddHref("components", 0x24);
}
