#include "PhysicMaterial.h"

PhysicMaterial::PhysicMaterial(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

PhysicMaterial::~PhysicMaterial()
{
}

void PhysicMaterial::Init()
{
	AddHref("parent", 0x18);
	AddFloat("sfxParam", 0x20);
	AddHref("visualSettings", 0x24);
}