#include "CreatureAttachSelfAction.h"

CreatureAttachSelfAction::CreatureAttachSelfAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureAttachSelfAction");
	Init();
}

CreatureAttachSelfAction::~CreatureAttachSelfAction()
{
}

void CreatureAttachSelfAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("attachTo", Enums::GetAttachTo(Read(0x24)));
	AddSource("locatorName", 0x28);
	FORNOT("memberLocatorName", 0x34, 0x0C)
	{
		AddSource("Item", i);
	}
	OpenCon("playAttachTo", 0x44);
	OpenCon("playAttachToWhenStopped", 0x48);
	OpenCon("playAttachToWhenStoppedBackground", 0x4C);
	OpenCon("playOnSelf", 0x50);
	OpenCon("playOnSelfWhenStopped", 0x54);
	AddBool("notifyCamera", 0x58);
}