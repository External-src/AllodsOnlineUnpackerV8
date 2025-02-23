#include "IndexedTexture.h"

IndexedTexture::IndexedTexture(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

IndexedTexture::~IndexedTexture()
{
}

void IndexedTexture::Init()
{
	AddBinFile("binaryFile", 0x18);
	AddBinFile("binaryFile2", 0x2C);
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