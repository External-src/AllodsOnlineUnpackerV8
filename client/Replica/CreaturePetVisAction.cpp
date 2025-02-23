#include "CreaturePetVisAction.h"

CreaturePetVisAction::CreaturePetVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreaturePetVisAction");
	Init();
}

CreaturePetVisAction::~CreaturePetVisAction()
{
}

void CreaturePetVisAction::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("visualScript", 0x24);
	AddBool("playOnAssistents", 0x28);
}