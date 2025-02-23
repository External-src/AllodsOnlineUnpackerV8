#include "CreatureColorAction.h"

CreatureColorAction::CreatureColorAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureColorAction");
	Init();
}

CreatureColorAction::~CreatureColorAction()
{
}

void CreatureColorAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("blendMode", Enums::GetBlendMode(Read(0x24)));
	AddRotation3("colorFactor", 0x28);
	AddInt("colorValue", 0x38);
	AddInt("priority", 0x3C);
	AddFloat("timeOff", 0x40);
	AddFloat("timeOn", 0x44);
	AddText("useOn", Enums::GetUseOn(Read(0x48)));
	AddBool("ignoreDisable", 0x4C);
}