#include "CreatureVisActionPlayOnUsedDevice.h"

CreatureVisActionPlayOnUsedDevice::CreatureVisActionPlayOnUsedDevice(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureVisActionPlayOnUsedDevice");
	Init();
}

CreatureVisActionPlayOnUsedDevice::~CreatureVisActionPlayOnUsedDevice()
{
}

void CreatureVisActionPlayOnUsedDevice::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("action", 0x24);
	AddBool("isBackgroundAlways", 0x28);
	AddBool("stopIfUsedObjectChanged", 0x29);
}