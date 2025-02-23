#include "CreatureProjectileAction.h"

CreatureProjectileAction::CreatureProjectileAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureProjectileAction");
	Init();
}

CreatureProjectileAction::~CreatureProjectileAction()
{
}

void CreatureProjectileAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("explosionFx", 0x24);
	OpenCon("offendTime", 0x2C);
	AddFloat("optionalSpeed", 0x30);
	OpenCon("pointOnCaster", 0x34);
	OpenCon("pointOnTarget", 0x38);
	AddHref("projectileFx", 0x3C);
	AddFloat("theGe", 0x44);
	AddBool("isInverted", 0x48);
	AddBool("isMultyProjectile", 0x49);
}