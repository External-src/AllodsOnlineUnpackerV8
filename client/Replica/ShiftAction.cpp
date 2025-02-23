#include "ShiftAction.h"

ShiftAction::ShiftAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.ShiftAction");
	Init();
}

ShiftAction::~ShiftAction()
{
}

void ShiftAction::Init()
{
	AddSource("visActionID", 0x14);
	AddFloat("verticalShift", 0x24);
}