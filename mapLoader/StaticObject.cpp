#include "StaticObject.h"

StaticObject::StaticObject(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

StaticObject::~StaticObject()
{
}

void StaticObject::Init()
{
	AddHref("Collision", 0x18);
	AddHref("ObjectTemplate", 0x20);
	AddSFX2("ambienceSound", 0x28);
	FORNOT("areaMiniMaps", 0x40, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddSFX2("music", 0x50);
	FORCON("parts", 0x68, 0x44)
	{
		OPENEX_X("ColorInfo", 0x4)
		{
			m->AddInt("ambientColor", 0x4);
			m->AddInt("occlusionColor", 0x8);
			m->AddInt("useCustomColor", 0x0C);
		}
		m->AddVector3("Position", 0x14);
		m->AddRotation3("Rotation", 0x20);
		m->AddFloat("Scale", 0x30);
		m->AddHref("StaticObjectTemplate", 0x34);
		m->OpenCon("data", 0x3C);
		m->AddBool("useManualColor", 0x40);
	}
	FORCON("serverLocators", 0x78, 0x30)
	{
		m->AddSource("boneName", 0x4);
		m->AddVector3("position", 0x10);
		m->AddRotation3("rotation", 0x1C);
		m->AddFloat("scale", 0x2C);
	}
	FORNOT("visibleZoneIndices", 0x88, 0x4)
	{
		m->AddInt("Item", i);
	}
	AddBool("coloredObject", 0x98);
}