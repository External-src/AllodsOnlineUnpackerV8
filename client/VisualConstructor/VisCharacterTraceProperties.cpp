#include "VisCharacterTraceProperties.h"

VisCharacterTraceProperties::VisCharacterTraceProperties(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

VisCharacterTraceProperties::~VisCharacterTraceProperties()
{
}

void VisCharacterTraceProperties::Init()
{
	FORCON("animations", 0x18, 0x18)
	{
		m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
		FORCONX("keys", 0x8, 0x14)
		{
			FORCONX("actions", 0x4, 0x1C)
			{
				m->AddHref("effects", 0x4);
				m->AddText("standartLocator", Enums::GetStandartLocator(m->Read(0x0C)));
				m->AddSource("uncommonLocator", 0x10);
			}
		}
	}
}