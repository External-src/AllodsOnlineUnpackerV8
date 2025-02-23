#include "HighlightCreatureVisAction.h"

HighlightCreatureVisAction::HighlightCreatureVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.HighlightCreatureVisAction");
	Init();
}

HighlightCreatureVisAction::~HighlightCreatureVisAction()
{
}

void HighlightCreatureVisAction::Init()
{
	AddSource("visActionID", 0x14);
	AddInt("color", 0x24);
}