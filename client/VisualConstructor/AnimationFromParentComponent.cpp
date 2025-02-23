#include "AnimationFromParentComponent.h"

AnimationFromParentComponent::AnimationFromParentComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.AnimationFromParentComponent");
	Init();
}

AnimationFromParentComponent::~AnimationFromParentComponent()
{
}

void AnimationFromParentComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	FORCON("animationsReplacements", 0x24, 0x18)
	{
		FORNOTX("forAnimations", 0x4, 0x4)
		{
			m->AddText("Item", Enums::GetAnimation(m->Read(i)));
		}
		m->AddText("play", Enums::GetAnimation(m->Read(0x14)));
	}
	AddHref("controller", 0x34);
	AddText("ifAnimationNotExistsRun", Enums::GetAnimation(Read(0x3C)));
	AddBool("skipBlendOptimization", 0x40);
	AddBool("synchronizeAnimationPosition", 0x41);
}
