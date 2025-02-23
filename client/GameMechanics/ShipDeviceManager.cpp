#include "ShipDeviceManager.h"

ShipDeviceManager::ShipDeviceManager(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.GameMechanics.ShipDeviceManager");
	Init();
}

ShipDeviceManager::~ShipDeviceManager()
{
}

void ShipDeviceManager::Init()
{

}