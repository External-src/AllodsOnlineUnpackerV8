#include "VICVisObjectByCharComponent.h"

VICVisObjectByCharComponent::VICVisObjectByCharComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICVisObjectByCharComponent");
	Init();
}

VICVisObjectByCharComponent::~VICVisObjectByCharComponent()
{
}

void VICVisObjectByCharComponent::Init()
{
	FORCON("cases", 0x18, 0x28)
	{
		FORNOTX("animation", 0x4, 0x4)
		{
			m->AddText("Item", Enums::GetAnimation(m->Read(i)));
		}
		FORNOTX("visCharacterTemplate", 0x14, 0x8)
		{
			m->AddHref("Item", i);
		}
		m->OpenCon("visObjComponent", 0x24);
	}
}