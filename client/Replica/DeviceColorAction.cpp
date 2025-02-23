#include "DeviceColorAction.h"

DeviceColorAction::DeviceColorAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceColorAction");
	Init();
}

DeviceColorAction::~DeviceColorAction()
{
}

void DeviceColorAction::Init()
{
	AddSource("visActionID", 0x14);
	AddRotation3("colorFactor", 0x28);
	AddInt("colorValue", 0x38);
	AddInt("priority", 0x3C);
	AddFloat("timeOff", 0x40);
	AddFloat("timeOn", 0x44);
}