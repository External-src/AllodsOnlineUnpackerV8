#include "CreatureScaleAction.h"

CreatureScaleAction::CreatureScaleAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureScaleAction");
	Init();
}

CreatureScaleAction::~CreatureScaleAction()
{
}

void CreatureScaleAction::Init()
{
	AddSource("visActionID", 0x14);
	AddFloat("scale", 0x24);
}