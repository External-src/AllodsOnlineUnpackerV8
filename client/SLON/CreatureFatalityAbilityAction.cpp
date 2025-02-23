#include "CreatureFatalityAbilityAction.h"

CreatureFatalityAbilityAction::CreatureFatalityAbilityAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureFatalityAbilityAction");
	Init();
}

CreatureFatalityAbilityAction::~CreatureFatalityAbilityAction()
{
}

void CreatureFatalityAbilityAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("fatalityType", Enums::GetFatalityType(Read(0x24)));
}