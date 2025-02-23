#include "Sound3DActionDevice.h"

Sound3DActionDevice::Sound3DActionDevice(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.Sound3DActionDevice");
	Init();
}

Sound3DActionDevice::~Sound3DActionDevice()
{
}

void Sound3DActionDevice::Init()
{
	AddSource("visActionID", 0x14);
	AddSFX("sound", 0x28);
	AddBool("forcedSoundStop", 0x44);
}