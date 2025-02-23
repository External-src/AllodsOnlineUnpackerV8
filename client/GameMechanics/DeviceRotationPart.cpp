#include "DeviceRotationPart.h"

DeviceRotationPart::DeviceRotationPart(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.GameMechanics.DeviceRotationPart");
	Init();
}

DeviceRotationPart::~DeviceRotationPart()
{
}

void DeviceRotationPart::Init()
{
}