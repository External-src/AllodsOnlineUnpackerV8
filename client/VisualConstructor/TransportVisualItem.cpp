#include "TransportVisualItem.h"

TransportVisualItem::TransportVisualItem(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

TransportVisualItem::~TransportVisualItem()
{
}

void TransportVisualItem::Init()
{
	FORNOT("disabledGeosets", 0x18, 0x0C)
	{
		m->AddSource("Item", i);
	}
	FORCON("replacedTextures", 0x28, 0x20)
	{
		m->AddInt("color", 0x4);
		m->AddInt("maskColor", 0x8);
		m->AddHref("replacement", 0x0C);
		m->AddSource("shapeName", 0x14);
	}
}