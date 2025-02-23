#include "AnimatedLight.h"

AnimatedLight::AnimatedLight(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

AnimatedLight::~AnimatedLight()
{
}

void AnimatedLight::Init()
{
	AddFloat("animationSpeed", 0x18);
	AddFloat("fps", 0x1C);
	FORCON("values", 0x20, 0x8)
	{
		m->AddInt("color", 0x4);
	}
}