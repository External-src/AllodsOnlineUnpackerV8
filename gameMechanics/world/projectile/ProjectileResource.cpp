#include "ProjectileResource.h"

ProjectileResource::ProjectileResource(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

ProjectileResource::~ProjectileResource()
{
}

void ProjectileResource::Init()
{
	FORNOT("parts", 0x18, 0x4)
	{
		m->OpenCon("Item", i);
	}
	AddFloat("corpulence", 0x2C);
	AddTxt("name", 0x30);
	OpenCon("spawnLocation", 0x40);
	AddBool("manualCorpulence", 0x44);
	AddFloat("altitude", 0x4C);
	AddHref("visObject", 0x50);
	AddBool("checkTransportCollision", 0x58);
}