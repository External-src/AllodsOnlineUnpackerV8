#include "ProjectileHolderPart.h"

ProjectileHolderPart::ProjectileHolderPart(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.ProjectileHolderPart");
	Init();
}

ProjectileHolderPart::~ProjectileHolderPart()
{
}

void ProjectileHolderPart::Init()
{
}