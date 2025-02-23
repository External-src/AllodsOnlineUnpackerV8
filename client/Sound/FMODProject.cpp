#include "FMODProject.h"



FMODProject::FMODProject(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\" "));
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}


FMODProject::~FMODProject()
{
}

void FMODProject::Init()
{
	AddHrefSource("fmodProject", 0x28);
	
	if (Module * m = OpenIn("fmodBanks", 0x18))
	{
		DWORD size = GetForSize(0x18);
		for (DWORD i = 0x0; i < size; i += 0x14)
		{
			m->AddHrefSource("Item", i);
		}
	}
}