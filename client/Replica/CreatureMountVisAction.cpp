#include "CreatureMountVisAction.h"

CreatureMountVisAction::CreatureMountVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureMountVisAction");
	Init();
}

CreatureMountVisAction::~CreatureMountVisAction()
{
}

void CreatureMountVisAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("alias", 0x24);
	AddHref("visualMount", 0x2C);
	AddBool("restorePrevMount", 0x34);
}