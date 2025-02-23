#include "InteractionAnimationPart.h"

InteractionAnimationPart::InteractionAnimationPart(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.InteractionAnimationPart");
	Init();
}

InteractionAnimationPart::~InteractionAnimationPart()
{
}

void InteractionAnimationPart::Init()
{
	OpenCon("interactionEndAction", 0x18);
	OpenCon("interactionStartAction", 0x1C);
}