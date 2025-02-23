#include "AlignCollisionComponent.h"

AlignCollisionComponent::AlignCollisionComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.AlignCollisionComponent");
	Init();
}

AlignCollisionComponent::~AlignCollisionComponent()
{
}

void AlignCollisionComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	AddFloat("endHeight", 0x24);
	AddSource("locatorName", 0x28);
	AddVector3("offset", 0x34);
	AddFloat("scale", 0x40);
	AddFloat("sphereRadius", 0x44);
	AddFloat("startHeight", 0x48);
	AddHref("visObject", 0x4C);
	AddFloat("yaw", 0x54);
	AddBool("alignNormal", 0x58);
	AddBool("checkNormal", 0x59);
	AddBool("fixedPosition", 0x5A);
	AddBool("getPrevObjectHeight", 0x5B);
	AddBool("lockScale", 0x5C);
	AddBool("placeAlways", 0x5D);
}

