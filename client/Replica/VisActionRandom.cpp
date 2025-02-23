#include "VisActionRandom.h"

VisActionRandom::VisActionRandom(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.VisActionRandom");
	Init();
}

VisActionRandom::~VisActionRandom()
{
}

void VisActionRandom::Init()
{
	AddSource("visActionID", 0x14);
	FORCON("elements", 0x24, 0x0C)
	{
		m->OpenCon("action", 0x4);
		m->AddFloat("probability", 0x8);
	}
}