#include "MountGroupResource.h"

MountGroupResource::MountGroupResource(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

MountGroupResource::~MountGroupResource()
{
}

void MountGroupResource::Init()
{
	FORNOT("mounts", 0x18, 0x8)
	{
		m->AddHref("Item", i);
	}
}