#include "CreatureRunVisActionResource.h"

CreatureRunVisActionResource::CreatureRunVisActionResource(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureRunVisActionResource");
	Init();
}

CreatureRunVisActionResource::~CreatureRunVisActionResource()
{
}

void CreatureRunVisActionResource::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("alias", 0x24);
	AddHref("resource", 0x2C);
}