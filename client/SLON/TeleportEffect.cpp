#include "TeleportEffect.h"

TeleportEffect::TeleportEffect(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.TeleportEffect");
	Init();
}

TeleportEffect::~TeleportEffect()
{
}

void TeleportEffect::Init()
{
	AddHref("summon", 0x18);
	AddHref("transitionCycle", 0x20);
	AddHref("transitionEndIn", 0x28);
	AddHref("transitionEndOut", 0x30);
}