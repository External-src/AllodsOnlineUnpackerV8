#include "RotationAnimationPart.h"

RotationAnimationPart::RotationAnimationPart(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.RotationAnimationPart");
	Init();
}

RotationAnimationPart::~RotationAnimationPart()
{
}

void RotationAnimationPart::Init()
{
	FORCON("pitchBones", 0x18, 0x14)
	{
		m->AddSource("bone", 0x4);
		m->AddFloat("multiplier", 0x10);
	}
	FORCON("yawBones", 0x28, 0x14)
	{
		m->AddSource("bone", 0x4);
		m->AddFloat("multiplier", 0x10);
	}
}