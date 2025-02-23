#include "VICPack.h"

VICPack::VICPack(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\" "));
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

VICPack::~VICPack()
{
}

void VICPack::Init()
{
	FORNOT("dynamicComponents", 0x18, 0x4)
	{
		m->OpenCon("Item", i);
	}
	FORNOT("staticComponents", 0x28, 0x4)
	{
		m->OpenCon("Item", i);
	}
}