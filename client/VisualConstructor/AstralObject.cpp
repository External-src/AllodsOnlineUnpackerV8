#include "AstralObject.h"

AstralObject::AstralObject(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

AstralObject::~AstralObject()
{
}

void AstralObject::Init()
{
	AddFloat("astralRadius", 0x18);
	OPENEX("effectFade", 0x1C)
	{
		m->AddFloat("end", 0x4);
		m->AddFloat("start", 0x8);
	}
	OPENEX("flareFade", 0x28)
	{
		m->AddFloat("end", 0x4);
		m->AddFloat("start", 0x8);
	}
	AddHref("flareTexture", 0x34);
	AddFloat("forceFieldRadius", 0x3C);
	AddFloat("maxSize", 0x40);
	FORCON("parts", 0x44, 0x14)
	{
		m->AddFloat("freezeDistance", 0x4);
		m->AddFloat("scale", 0x8);
		m->AddHref("visObject", 0x0C);
	}
}