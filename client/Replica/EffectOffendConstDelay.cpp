#include "EffectOffendConstDelay.h"

EffectOffendConstDelay::EffectOffendConstDelay(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.EffectOffendConstDelay");
	Init();
}

EffectOffendConstDelay::~EffectOffendConstDelay()
{
}

void EffectOffendConstDelay::Init()
{
	AddInt("delay", 0x18);
}