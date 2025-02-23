#include "TLScriptsPart.h"

TLScriptsPart::TLScriptsPart(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.TLScriptsPart");
	Init();
}

TLScriptsPart::~TLScriptsPart()
{
}

void TLScriptsPart::Init()
{
	AddFloat("operationPriority", 0x18);
	FORCON("techLevels", 0x1C, 0x1C)
	{
		m->AddHref("collision", 0x4);
		m->AddHref("object", 0x0C);
		m->AddHref("quality", 0x14);
	}
}