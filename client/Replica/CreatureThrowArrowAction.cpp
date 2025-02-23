#include "CreatureThrowArrowAction.h"

CreatureThrowArrowAction::CreatureThrowArrowAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureThrowArrowAction");
	Init();
}

CreatureThrowArrowAction::~CreatureThrowArrowAction()
{
}

void CreatureThrowArrowAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("additionalEffectFx", 0x24);
	AddHref("arrow", 0x2C);
	AddInt("arrowInTargetTime", 0x34);
	AddSource("effectBone", 0x38);
	AddInt("enchantedArrowIndex", 0x44);
	AddInt("fixedThrowDuration", 0x48);
	OpenCon("offendTime", 0x4C);
	AddFloat("pointInTargetMax", 0x50);
	AddFloat("pointInTargetMin", 0x54);
	AddFloat("theGe", 0x58);
	AddBool("useMeleeWeapon", 0x5C);
	AddBool("usePointInArrow", 0x5D);
}