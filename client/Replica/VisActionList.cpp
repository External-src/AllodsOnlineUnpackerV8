#include "VisActionList.h"

VisActionList::VisActionList(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.VisActionList");
	Init();
}

VisActionList::~VisActionList()
{
}

void VisActionList::Init()
{
	AddSource("visActionID", 0x14);
	FORNOT("elements", 0x24, 0x4)
	{
		m->OpenCon("Item", i);
	}
	AddText("play", Enums::GetPlay(Read(0x34)));
	OpenCon("playWhile", 0x38);
	AddBool("preconditional", 0x3C);
	AddBool("restartOnVisualChange", 0x3D);
	AddBool("stopOnDeath", 0x3E);
	AddBool("stopWhileWhenElementsEnded", 0x3F);
}