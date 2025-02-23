#include "PostEffectParams.h"

PostEffectParams::PostEffectParams(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

PostEffectParams::~PostEffectParams()
{
}

void PostEffectParams::Init()
{
	OPENEX("blurAddFactor", 0x18)
	{
		m->AddRotation3("add", 0x4);
		m->AddRotation3("mul", 0x14);
	}
	AddFloat("blurRadius", 0x3C);
	OPENEX("diffuseFactor", 0x40)
	{
		m->AddRotation3("add", 0x4);
		m->AddRotation3("mul", 0x14);
	}
	OPENEX("overlayFactor", 0x64)
	{
		m->AddRotation3("add", 0x4);
		m->AddRotation3("mul", 0x14);
	}
}