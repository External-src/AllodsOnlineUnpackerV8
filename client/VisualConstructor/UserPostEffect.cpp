#include "UserPostEffect.h"

UserPostEffect::UserPostEffect(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

UserPostEffect::~UserPostEffect()
{
}

void UserPostEffect::Init()
{
	AddFloat("cycleTimeMS", 0x18);
	AddInt("fadeInTimeMSec", 0x1C);
	AddInt("fadeOutTimeMSec", 0x20);
	AddFloat("maxBumpFactor", 0x24);
	AddFloat("maxColorFactor", 0x28);
	AddFloat("maxScaleFactor", 0x2C);
	AddFloat("minBumpFactor", 0x30);
	AddFloat("minColorFactor", 0x34);
	AddFloat("minScaleFactor", 0x38);
	AddInt("priority", 0x3C);
	AddHref("textureAdditive", 0x40);
	AddHref("textureBump", 0x48);
	AddHref("textureMultiply", 0x50);
	AddBool("mulEffectPost", 0x58);
}