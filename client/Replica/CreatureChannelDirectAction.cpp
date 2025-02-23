#include "CreatureChannelDirectAction.h"

CreatureChannelDirectAction::CreatureChannelDirectAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureChannelDirectAction");
	Init();
}

CreatureChannelDirectAction::~CreatureChannelDirectAction()
{
}

void CreatureChannelDirectAction::Init()
{
	AddSource("visActionID", 0x14);
	OpenCon("alternativeEndPoint", 0x24);
	OpenCon("alternativeStartPoint", 0x28);
	AddHref("channelingFx", 0x2C);
	OpenCon("endPoint", 0x34);
	AddInt("fadeInTime", 0x38);
	AddInt("fadeOutTime", 0x3C);
	AddFloat("fxLength", 0x40);
	AddText("multyTargetMode", Enums::GetTargetMode(Read(0x44)));
	OpenCon("offendTime", 0x48);
	OPENEX("secondaryTargetParams", 0x4C)
	{
		m->AddHref("channelingFx", 0x4);
		m->AddInt("fadeInTime", 0x0C);
		m->AddInt("fadeOutTime", 0x10);
		m->AddFloat("fxLength", 0x14);
		m->OpenCon("offendTime", 0x18);
		m->AddFloat("velocity", 0x1C);
		m->AddBool("scaleTextureU", 0x20);
		m->AddBool("scaleTextureV", 0x21);
	}
	OpenCon("startPoint", 0x70);
	AddFloat("velocity", 0x74);
	AddBool("scaleTextureU", 0x78);
	AddBool("scaleTextureV", 0x79);
}