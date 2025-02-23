#include "UsableDeviceClientPart.h"

UsableDeviceClientPart::UsableDeviceClientPart(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.UsableDeviceClientPart");
	Init();
}

UsableDeviceClientPart::~UsableDeviceClientPart()
{
}

void UsableDeviceClientPart::Init()
{
	AddText("type", Enums::GetTypeShip(Read(0x18)));
}