#include "AstralMobHitLocator.h"

AstralMobHitLocator::AstralMobHitLocator(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.AstralMobHitLocator");
	Init();
}

AstralMobHitLocator::~AstralMobHitLocator()
{
}

void AstralMobHitLocator::Init()
{
}