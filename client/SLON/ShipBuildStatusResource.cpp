#include "ShipBuildStatusResource.h"

ShipBuildStatusResource::ShipBuildStatusResource(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

ShipBuildStatusResource::~ShipBuildStatusResource()
{
}

void ShipBuildStatusResource::Init()
{
	FORCON("stages", 0x18, 0x10)
	{
		m->AddHref("object", 0x4);
		m->AddFloat("percent", 0x0C);
	}
}