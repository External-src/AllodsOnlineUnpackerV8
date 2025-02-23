#include "SkeletalAnimation.h"



SkeletalAnimation::SkeletalAnimation(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\" "));
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}


SkeletalAnimation::~SkeletalAnimation()
{
}

void SkeletalAnimation::Init()
{
	AddAABB("aabb", 0x18);
	AddAABB("aabbLastFrame", 0x30);
	OPENEX("animation", 0x48)
	{
		m->AddInt("localID", 0x4);
		m->AddInt("size", 0x8);
	}
	FORCON("animationEvents", 0x54, 0x18)
	{
		m->AddFloat("event", 0x4);
		m->AddInt("id", 0x8);
		m->AddSource("name", 0x0C);
	}
	AddBinFile("binaryFile", 0x64);
	AddInt("binaryVersion", 0x78);
	AddFloat("blendTime", 0x7C);
	AddInt("endFrame", 0x80);
	AddFloat("fps", 0x84);
	AddInt("loopFrame", 0x88);
	AddInt("scriptID", 0x8C);
	AddSource("scriptName", 0x90);
	AddFloat("speed", 0x9C);
	AddInt("startFrame", 0xA0);
	AddBool("looped", 0xA4);
}
