#include "MountSkin.h"

MountSkin::MountSkin(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

MountSkin::~MountSkin()
{
}

void MountSkin::Init()
{
	AddTxt("Description", 0x18);
	AddTxt("Name", 0x28);
	AddTxt("SourceDescription", 0x38);
	AddHref("alias", 0x48);
	AddHref("image", 0x50);
	FORNOT("keys", 0x58, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddTxt("p2pSourceDescription", 0x68);
	AddHref("unlock", 0x78);
	AddHref("visualMount", 0x80);
	OpenCon("visualScript", 0x88);
	AddBool("p2p", 0x8C);
}