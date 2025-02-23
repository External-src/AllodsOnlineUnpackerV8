#include "TexturePatch.h"

TexturePatch::TexturePatch(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

TexturePatch::~TexturePatch()
{
}

void TexturePatch::Init()
{
	FORCON("female", 0x18, 0x20)
	{
		OPENEX_X("rectangle", 0x4)
		{
			m->AddFloat("x1", 0x4);
			m->AddFloat("x2", 0x8);
			m->AddFloat("y1", 0x0C);
			m->AddFloat("y2", 0x10);
		}
		m->AddHref("texture", 0x18);
	}
	FORCON("male", 0x28, 0x20)
	{
		OPENEX_X("rectangle", 0x4)
		{
			m->AddFloat("x1", 0x4);
			m->AddFloat("x2", 0x8);
			m->AddFloat("y1", 0x0C);
			m->AddFloat("y2", 0x10);
		}
		m->AddHref("texture", 0x18);
	}
	FORCON("unisex", 0x38, 0x20)
	{
		OPENEX_X("rectangle", 0x4)
		{
			m->AddFloat("x1", 0x4);
			m->AddFloat("x2", 0x8);
			m->AddFloat("y1", 0x0C);
			m->AddFloat("y2", 0x10);
		}
		m->AddHref("texture", 0x18);
	}
}