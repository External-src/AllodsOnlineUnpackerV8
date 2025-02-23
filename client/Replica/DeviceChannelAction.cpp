#include "DeviceChannelAction.h"

DeviceChannelAction::DeviceChannelAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceChannelAction");
	Init();
}

DeviceChannelAction::~DeviceChannelAction()
{
}

void DeviceChannelAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("channelingFx", 0x28);
	OpenCon("endPoint", 0x30);
	AddInt("fadeInTime", 0x34);
	AddInt("fadeOutTime", 0x38);
	OpenCon("startPoint", 0x3C);
	AddFloat("velocity", 0x40);
}