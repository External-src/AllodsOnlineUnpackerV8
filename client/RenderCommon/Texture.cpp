#include "Texture.h"

Texture::Texture(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\" "));
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}


Texture::~Texture()
{
}

void Texture::Init()
{
	//string path = GetPatch();
	//int st = path.rfind('.');
	//if (st != string::npos)
	//{
	//	path.erase(st + 1, 3);
	//	path += "bin";
	//	//AddBinSize(path);
	//	OPENEX("binaryFile", 0x18)
	//	{
	//		m->AddAttribute("href", "/" + path);
	//	}
	//}
	AddBinFile("binaryFile", 0x18);
	AddBinFile("binaryFile2", 0x2C);
	//binaryFile2 0x2C
	AddInt("height", 0x40);
	AddInt("width", 0x5C);
	AddInt("mipSW", 0x44);
	AddInt("mipsNumber", 0x48);
	AddText("pool", Enums::GetPool(Read(0x4C)));
	AddInt("realHeight", 0x50);
	AddInt("realWidth", 0x54);
	AddText("type", Enums::GetDXT(Read(0x58)));
	AddBool("alphaTex", 0x60);
	AddBool("atlasPart", 0x61);
	AddBool("disableLODControl", 0x62);
	AddBool("generateMipChain", 0x63);
	AddBool("wrap", 0x64);
}
