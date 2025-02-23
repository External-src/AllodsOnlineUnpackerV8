#include "VisualMountClass.h"

VisualMountClass::VisualMountClass(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

VisualMountClass::~VisualMountClass()
{
}

void VisualMountClass::Init()
{
	OPENEX("animationSettings", 0x18)
	{
		FORCONX("complexAnimations", 0x4, 0x14)
		{
			m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
			m->AddText("playOnMount", Enums::GetAnimation(m->Read(0x8)));
			m->AddText("playOnRiderBottom", Enums::GetAnimation(m->Read(0x0C)));
			m->AddText("playOnRiderTop", Enums::GetAnimation(m->Read(0x10)));
		}
		m->AddHref("playOnMount", 0x14);
		m->AddHref("playOnRider", 0x1C);
		m->AddHref("playOnRiderTopOnly", 0x24);
		FORNOTX("visualDismount", 0x2C, 0x14)
		{
			m->AddText("Item", Enums::GetAnimation(m->Read(i)));
		}
	}
	OPENEX("controlParameters", 0x54)
	{
		FORCONX("speedFactorForward", 0x18, 0x28)
		{
			m->AddFloat("startTime", 0x4);
			m->AddFloat("startVelocity", 0x8);
			m->AddFloat("stopTime", 0x0C);
			m->AddFloat("stopVelocity", 0x10);
		}
	}
	AddText("dismountAnimation", Enums::GetAnimation(Read(0x80)));
	OPENEX("fxSettings", 0x84)
	{
		FORNOTX("mountLocators", 0x4, 0x0C)
		{
			m->AddSource("Item", i);
		}
	}
	FORNOT("hiddenDressSlots", 0x98, 0x14)
	{
		m->AddText("Item", Enums::GetSlot(m->Read(i)));
	}
	OPENEX("jumpSettings", 0xA8)
	{
		m->AddFloat("jumpMinVelocity", 0x4);
		m->AddHref("specialJump", 0x8);
		m->AddInt("specialJumpPause", 0x10);
		m->AddText("useJump", Enums::GetUseJump(m->Read(0x14)));
	}
	AddHref("levelChangedScript", 0xC0);
	OPENEX("pitchParameters", 0xC8)
	{
		m->AddFloat("maxPitch", 0x4);
		m->AddInt("minStepDeltaT", 0x8);
		m->AddInt("minStepDeltaTMainAvatar", 0x0C);
		m->AddFloat("minTurnRadius", 0x10);
		m->AddFloat("minVelocity", 0x14);
		m->AddFloat("minVelocityPitch", 0x18);
		m->AddFloat("pitchMaxVelocity", 0x1C);
		m->AddFloat("topVelocity", 0x20);
		m->AddFloat("topVelocityPitch", 0x24);
	}
	OPENEX("reinsSettings", 0xF0)
	{
		m->AddHref("disablingAnimations", 0x4);
		m->AddSource("handBone", 0x0C);
		m->AddSource("handBone01", 0x18);
		m->AddText("member", Enums::GetMember(m->Read(0x24)));
		m->AddSource("reinsBone", 0x28);
		m->AddSource("reinsBone01", 0x34);
		m->AddBool("use", 0x40);
	}
	AddText("riderOrientation", Enums::GetRiderOrient(Read(0x134)));
	AddText("sitAnimation", Enums::GetAnimation(Read(0x138)));
	AddHref("skinChangedScript", 0x13C);
	AddHref("summonVisualScript", 0x144);
	AddBool("nonDismountable", 0x14C);
	AddBool("useRiderSpineTurn", 0x14D);
}