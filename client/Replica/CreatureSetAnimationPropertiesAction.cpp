#include "CreatureSetAnimationPropertiesAction.h"

CreatureSetAnimationPropertiesAction::CreatureSetAnimationPropertiesAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureSetAnimationPropertiesAction");
	Init();
}

CreatureSetAnimationPropertiesAction::~CreatureSetAnimationPropertiesAction()
{
}

void CreatureSetAnimationPropertiesAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("animationProperties", 0x24);
	AddText("useOn", Enums::GetUseOn(Read(0x2C)));
}