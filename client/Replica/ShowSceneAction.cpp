#include "ShowSceneAction.h"

ShowSceneAction::ShowSceneAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.ShowSceneAction");
	Init();
}

ShowSceneAction::~ShowSceneAction()
{
}

void ShowSceneAction::Init()
{
	AddSource("visActionID", 0x14);
	AddHref("scene", 0x28);
	AddHref("script", 0x30);
	AddBool("destroyImmediately", 0x38);
}