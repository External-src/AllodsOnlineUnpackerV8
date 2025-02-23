#include "ShipResource.h"

ShipResource::ShipResource(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

ShipResource::~ShipResource()
{
}

void ShipResource::Init()
{
	FORTYPE("parts", 0x18, 0x4);
	AddFloat("corpulence", 0x2C);
	AddTxt("name", 0x30);
	AddBool("manualCorpulence", 0x44);
	AddInt("health", 0x4C);
	AddHref("image", 0x50);
	FORCON("visualShips", 0x58, 0x0C)
	{
		m->AddHref("visualShip", 0x4);
	}
	AddBool("drawInterface", 0x68);
}