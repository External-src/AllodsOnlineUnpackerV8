#include "CreatureEnlargeFovAction.h"

CreatureEnlargeFovAction::CreatureEnlargeFovAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureEnlargeFovAction");
	Init();
}

CreatureEnlargeFovAction::~CreatureEnlargeFovAction()
{
}

void CreatureEnlargeFovAction::Init()
{
	AddSource("visActionID", 0x14);
	AddFloat("actionTime", 0x24);
	AddFloat("fadeInTime", 0x28);
	AddFloat("fadeOutTime", 0x2C);
	AddFloat("fovCoefficient", 0x30);
	AddBool("onlyIfOnMainAvatar", 0x34);
}