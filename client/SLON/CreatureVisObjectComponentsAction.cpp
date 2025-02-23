#include "CreatureVisObjectComponentsAction.h"

CreatureVisObjectComponentsAction::CreatureVisObjectComponentsAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureVisObjectComponentsAction");
	Init();
}

CreatureVisObjectComponentsAction::~CreatureVisObjectComponentsAction()
{
}

void CreatureVisObjectComponentsAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("member", Enums::GetMember(Read(0x24)));
	FORNOT("visObjComponents", 0x28, 0x4)
	{
		m->OpenCon("Item", i);
	}
	AddBool("stopOnDeath", 0x38);
}