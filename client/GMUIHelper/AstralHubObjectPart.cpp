#include "AstralHubObjectPart.h"

AstralHubObjectPart::AstralHubObjectPart(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.GMUIHelper.AstralHubObjectPart");
	Init();
}

AstralHubObjectPart::~AstralHubObjectPart()
{
}

void AstralHubObjectPart::Init()
{
	AddHref("collisionIcon", 0x18);
	AddFloat("collisionRadius", 0x20);
	AddTxt("description", 0x24);
	AddHref("image", 0x34);
	AddTxt("name", 0x3C);
}