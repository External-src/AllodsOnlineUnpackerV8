#include "ScanerDevicePart.h"

ScanerDevicePart::ScanerDevicePart(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.ScanerDevicePart");
	Init();
}

ScanerDevicePart::~ScanerDevicePart()
{
}

void ScanerDevicePart::Init()
{
	FORCON("globalBones", 0x18, 0x14)
	{
		m->AddFloat("multiplier", 0x4);
		m->AddSource("name", 0x8);
	}
	AddSource("locatorName", 0x3C);
	OPENEX("ourHub", 0x48)
	{
		m->AddHref("collision", 0x4);
		m->AddHref("obj", 0x0C);
	}
	FORCON("pitchBones", 0x5C, 0x14)
	{
		m->AddFloat("multiplier", 0x4);
		m->AddSource("name", 0x8);
	}
	FORCON("rollBones", 0x6C, 0x14)
	{
		m->AddFloat("multiplier", 0x4);
		m->AddSource("name", 0x8);
	}
	AddFloat("sphereRadius", 0x7C);
	AddFloat("stripeTextureSize", 0x80);
	FORCON("yawBones", 0x84, 0x14)
	{
		m->AddFloat("multiplier", 0x4);
		m->AddSource("name", 0x8);
	}
}