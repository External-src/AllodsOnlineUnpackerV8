#include "UnlockResource.h"

UnlockResource$::UnlockResource$(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

UnlockResource$::~UnlockResource$()
{
}

void UnlockResource$::Init()
{
	AddText("binding", Enums::GetUBinding(Read(0x18)));
	AddHref("category", 0x1C);
	AddTxt("description", 0x24);
	AddHref("image", 0x34);
	AddTxt("name", 0x3C);
	AddSource("sysUIScriptName", 0x4C);
	AddBool("isHidden", 0x58);
}