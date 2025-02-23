#include "SphereCollisionHandler.h"

SphereCollisionHandler::SphereCollisionHandler(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.GameMechanics.SphereCollisionHandler");
	Init();
}

SphereCollisionHandler::~SphereCollisionHandler()
{
}

void SphereCollisionHandler::Init()
{
	AddFloat("mass", 0x18);
	AddFloat("radius", 0x1C);
}