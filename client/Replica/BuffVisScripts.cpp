#include "BuffVisScripts.h"

BuffVisScripts::BuffVisScripts(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

BuffVisScripts::~BuffVisScripts()
{
}

void BuffVisScripts::Init()
{
	AddTxt("Description", 0x18);
	OpenCon("action", 0x28);
	OpenCon("postAction", 0x2C);
	FORCON("stackCountVisScripts", 0x30, 0x18)
	{
		m->OpenCon("allTimeScript", 0x4);
		m->OpenCon("enterFromBiggerScript", 0x8);
		m->OpenCon("enterFromLowerScript", 0x0C);
		m->AddFloat("maxValue", 0x10);
		m->AddBool("playIfStateSkipedFromBigger", 0x14);
		m->AddBool("playIfStateSkipedFromLower", 0x15);
	}
	AddBool("restartOnIncStackCount", 0x40);
}