#include "PostEffectVisAction.h"

PostEffectVisAction::PostEffectVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.PostEffectVisAction");
	Init();
}

PostEffectVisAction::~PostEffectVisAction()
{
}

void PostEffectVisAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("userPostEffect", 0x24);
}