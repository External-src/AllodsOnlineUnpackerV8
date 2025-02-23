#include "ProceduralEffectVisAction.h"

ProceduralEffectVisAction::ProceduralEffectVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.ProceduralEffectVisAction");
	Init();
}

ProceduralEffectVisAction::~ProceduralEffectVisAction()
{
}

void ProceduralEffectVisAction::Init()
{
	AddSource("visActionID", 0x14);
	AddInt("priority", 0x24);
	AddHref("proceduralEffect", 0x28);
	AddFloat("timeOff", 0x30);
	AddFloat("timeOn", 0x34);
	AddText("useOn", Enums::GetUseOn(Read(0x38)));
}