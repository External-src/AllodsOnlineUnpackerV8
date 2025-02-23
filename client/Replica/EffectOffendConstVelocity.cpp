#include "EffectOffendConstVelocity.h"

EffectOffendConstVelocity::EffectOffendConstVelocity(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.EffectOffendConstVelocity");
	Init();
}

EffectOffendConstVelocity::~EffectOffendConstVelocity()
{
}

void EffectOffendConstVelocity::Init()
{
	AddInt("delay", 0x18);
	AddFloat("maxDist", 0x1C);
	AddFloat("velocity", 0x20);
}