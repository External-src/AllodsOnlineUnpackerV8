#include "DeviceVisEffectsAction.h"

DeviceVisEffectsAction::DeviceVisEffectsAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceVisEffectsAction");
	Init();
}

DeviceVisEffectsAction::~DeviceVisEffectsAction()
{
}

void DeviceVisEffectsAction::Init()
{
	AddSource("visActionID", 0x14);
	FORCON("visualEffects", 0x28, 0x2C)
	{
		m->AddInt("delay", 0x4);
		m->AddHref("effectFx", 0x8);
		m->AddInt("fadeInTime", 0x10);
		m->AddInt("fadeOutTime", 0x14);
		m->AddSource("locatorName", 0x18);
		m->AddFloat("scale", 0x24);
		m->AddBool("fixPoint", 0x28);
		m->AddBool("lockScale", 0x29);
	}
}