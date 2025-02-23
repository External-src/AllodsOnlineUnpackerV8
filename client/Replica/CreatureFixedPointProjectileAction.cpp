#include "CreatureFixedPointProjectileAction.h"

CreatureFixedPointProjectileAction::CreatureFixedPointProjectileAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureFixedPointProjectileAction");
	Init();
}

CreatureFixedPointProjectileAction::~CreatureFixedPointProjectileAction()
{
}

void CreatureFixedPointProjectileAction::Init()
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
	FORCON("lines", 0x50, 0x10)
	{
		m->AddInt("endPointIndex", 0x4);
		m->AddInt("startPointIndex", 0x8);
		m->AddInt("throwDuration", 0x0C);
	}
}