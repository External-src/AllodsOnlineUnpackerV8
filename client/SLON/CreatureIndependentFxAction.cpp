#include "CreatureIndependentFxAction.h"

CreatureIndependentFxAction::CreatureIndependentFxAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureIndependentFxAction");
	Init();
}

CreatureIndependentFxAction::~CreatureIndependentFxAction()
{
}

void CreatureIndependentFxAction::Init()
{
	AddSource("visActionID", 0x14);
	AddFloat("lifeTime", 0x24);
	AddVector3("offset", 0x28);
	AddVector3("rotation", 0x34);
	AddFloat("scale", 0x40);
	AddInt("visEventPointIndex", 0x44);
	AddHref("visObject", 0x48);
	AddBool("isRelative", 0x50);
	AddBool("useCastPoint", 0x51);
}