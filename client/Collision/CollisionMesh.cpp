#include "CollisionMesh.h"

CollisionMesh::CollisionMesh(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

CollisionMesh::~CollisionMesh()
{
}

void CollisionMesh::Init()
{
	AddAABB("aabb", 0x18);
	AddBinFile("binaryFile", 0x30);
	AddInt("binaryVersion", 0x44);
	AddInt("clipMask", 0x48);
	FORNOT("customMaterials", 0x4C, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddHref("defaultMaterial", 0x5C);
}