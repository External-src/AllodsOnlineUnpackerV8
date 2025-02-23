#include "StateComponent.h"

StateComponent::StateComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.StateComponent");
	Init();
}

StateComponent::~StateComponent()
{
}

void StateComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	FORCON("animationKeys", 0x24, 0x0C)
	{
		m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
		m->AddFloat("startTime", 0x8);
	}
	FORNOT("animations", 0x34, 0x4)
	{
		m->AddText("Item", Enums::GetAnimation(m->Read(i)));
	}
	OpenCon("component", 0x44);
	AddHref("controller", 0x48);
	AddBool("stopForOtherAnimation", 0x50);
	AddBool("synchronizeAnimationPosition", 0x51);
	AddBool("updateOnlyByFeedBacks", 0x52);
}
