#include "SkinListResource.h"

SkinListResource::SkinListResource(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

SkinListResource::~SkinListResource()
{
}

void SkinListResource::Init()
{
	FORNOT("skins", 0x18, 0x8)
	{
		m->AddHref("Item", i);
	}
}