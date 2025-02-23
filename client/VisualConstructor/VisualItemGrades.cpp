#include "VisualItemGrades.h"

VisualItemGrades::VisualItemGrades(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VisualItemGrades");
	Init();
}

VisualItemGrades::~VisualItemGrades()
{
}

void VisualItemGrades::Init()
{
	AddHref("element", 0x18);
	FORNOT("gradeVisuals", 0x20, 0x8)
	{
		m->AddHref("Item", i);
	}
}