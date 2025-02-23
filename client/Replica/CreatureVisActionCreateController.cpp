#include "CreatureVisActionCreateController.h"

CreatureVisActionCreateController::CreatureVisActionCreateController(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureVisActionCreateController");
	Init();
}

CreatureVisActionCreateController::~CreatureVisActionCreateController()
{
}

void CreatureVisActionCreateController::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("controller", 0x24);
	AddSource("controllerName", 0x2C);
	OPENEX("parentController", 0x38)
	{
		m->AddSource("specialControllerName", 0x4);
		m->AddText("type", Enums::GetVisType(m->Read(0x10)));
	}
}