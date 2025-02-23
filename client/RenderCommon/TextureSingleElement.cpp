#include "TextureSingleElement.h"

TextureSingleElement::TextureSingleElement(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

TextureSingleElement::~TextureSingleElement()
{
}

void TextureSingleElement::Init()
{
	AddHref("atlas", 0x18);
	AddInt("height", 0x20);
	AddHref("key", 0x24);
	AddInt("sourceFileCRC", 0x2C);
	AddInt("width", 0x30);
}