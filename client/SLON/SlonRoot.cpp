#include "SlonRoot.h"

SlonRoot::SlonRoot(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

SlonRoot::~SlonRoot()
{
}

void SlonRoot::Init()
{
	FORCON("fatalities", 0xB8, 0x1C)
	{
		m->OpenCon("casterFxScript", 0x4);
		m->AddFloat("fadeDuration", 0x8);
		m->AddFloat("fadeStartTime", 0x0C);
		m->OpenCon("offenderDeathScript", 0x10);
		m->AddFloat("sparkDelay", 0x14);
		m->AddText("type", Enums::GetFatalityType(m->Read(0x18)));
	}
}