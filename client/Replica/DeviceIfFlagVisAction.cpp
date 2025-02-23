#include "DeviceIfFlagVisAction.h"

DeviceIfFlagVisAction::DeviceIfFlagVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceIfFlagVisAction");
	Init();
}

DeviceIfFlagVisAction::~DeviceIfFlagVisAction()
{
}

void DeviceIfFlagVisAction::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("visScriptEnd", 0x28);
	OpenCon("visScriptLoop", 0x2C);
	OpenCon("visScriptStart", 0x30);
	AddHref("visualFlag", 0x34);
}