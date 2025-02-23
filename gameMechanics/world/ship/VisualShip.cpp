#include "VisualShip.h"

VisualShip::VisualShip(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

VisualShip::~VisualShip()
{
}

void VisualShip::Init()
{
	AddText("cannonVisualType", Enums::GetVisualTypeShip(Read(0x18)));
	FORNOT("compatibleSkins", 0x1C, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddTxt("description", 0x2C);
	AddHref("image", 0x3C);
	AddTxt("name", 0x44);
	FORNOT("parts", 0x54, 0x4)
	{
		m->OpenCon("Item", i);
	}
	AddFloat("radius", 0x64);
	FORCON("slots", 0x68, 0x58)
	{
		FORNOTX("allowedDeviceTypes", 0x4, 0x8)
		{
			m->AddHref("Item", i);
		}
		m->AddVector3("coord", 0x14);
		m->OpenCon("interfaceData", 0x20);
		m->AddText("name", Enums::GetSlotShip(m->Read(0x24)));
		m->AddFloat("pitch", 0x28);
		m->AddFloat("pitchRange", 0x2C);
		m->AddFloat("roll", 0x30);
		m->AddRotation3("rotation", 0x34);
		m->AddFloat("scale", 0x44);
		m->AddText("side", Enums::GetSideShip(m->Read(0x48)));
		m->AddFloat("yaw", 0x4C);
		m->AddFloat("yawRange", 0x50);
		m->AddBool("canBeEmpty", 0x54);
		m->AddBool("isLootSlot", 0x55);
	}
	AddHref("steeringParams", 0x78);
	AddHref("transportVisObject", 0x80);
	AddHref("unlock", 0x88);
}