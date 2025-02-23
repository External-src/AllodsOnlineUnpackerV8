#include "AreaEffect.h"

AreaEffect::AreaEffect(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

AreaEffect::~AreaEffect()
{
}

void AreaEffect::Init()
{
	AddInt("areaEffectGridStep", 0x18);
	AddHref("astralParams", 0x1C);
	AddHref("effect", 0x24);
	AddFloat("fadeFactor", 0x2C);
	AddFloat("maxEffectSpeed", 0x30);
	AddBool("disableAstralFX", 0x34);
	AddBool("randomRotate", 0x35);
}