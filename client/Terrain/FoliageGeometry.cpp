#include "FoliageGeometry.h"

FoliageGeometry::FoliageGeometry(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

FoliageGeometry::~FoliageGeometry()
{
}

void FoliageGeometry::Init()
{
	FORCON("quads", 0x18, 0x18)
	{
		m->AddFloat("u", 0x4);
		m->AddFloat("v", 0x8);
		m->AddFloat("x", 0x0C);
		m->AddFloat("y", 0x10);
		m->AddFloat("z", 0x14);
	}
}