#include "Collision.h"

Collision::Collision(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

Collision::~Collision()
{
}

void Collision::Init()
{
	AddAABB("aabb", 0x18);
	AddHref("collisionMesh", 0x30);
	AddText("volume", Enums::GetVolume(Read(0x38)));
	AddBool("hasVisualCollision", 0x3C);
}