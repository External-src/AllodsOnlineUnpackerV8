#include "DeviceVisActionLoopAction.h"

DeviceVisActionLoopAction::DeviceVisActionLoopAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DeviceVisActionLoopAction");
	Init();
}

DeviceVisActionLoopAction::~DeviceVisActionLoopAction()
{
}

void DeviceVisActionLoopAction::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("actionToLoop", 0x28);
	AddInt("repeat", 0x2C);
	AddFloat("totalTime", 0x30);
}