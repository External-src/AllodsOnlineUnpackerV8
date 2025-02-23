#include "DeviceAnimationAction.h"

DeviceAnimationAction::DeviceAnimationAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceAnimationAction");
	Init();
}

DeviceAnimationAction::~DeviceAnimationAction()
{
}

void DeviceAnimationAction::Init()
{
	AddSource("visActionID", 0x14);
	OPENEX("advanced", 0x28)
	{
		m->AddFloat("speed", 0x4);
		m->AddBool("backgroundAfterFirstKey", 0x8);
	}
	FORNOT("animations", 0x34, 0x4)
	{
		m->AddText("Item", Enums::GetAnimation(m->Read(i)));
	}
	AddInt("channelId", 0x44);
	AddText("mode", Enums::GetAnimMode(Read(0x48)));
}