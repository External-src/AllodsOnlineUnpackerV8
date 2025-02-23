#include "AnimationProperties.h"

AnimationProperties::AnimationProperties(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\" "));
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}


AnimationProperties::~AnimationProperties()
{
}

void AnimationProperties::Init()
{
	AddSource("headBoneName", 0x18);
	AddFloat("headTurnTime", 0x24);
	AddText("kind", Enums::GetKind(Read(0x28)));
	AddFloat("legAlignTime", 0x2C);
	AddFloat("legRunTurnTime", 0x30);
	AddFloat("maxHeadAngle", 0x34);
	AddFloat("headTurnTime", 0x38);
	OPENEX("specialShuffleParams", 0x3C)
	{
		m->AddFloat("minChangeRotationAngle", 0x4);
		m->AddFloat("minChangeVelocityAngle", 0x8);
	}
	AddSource("spineBoneName", 0x48);
	AddFloat("swimHeight", 0x54);
	OPENEX("targetTrackingParams", 0x58)
	{
		FORNOTX("addedToUseAnimations", 0x4, 0x14)
		{
			m->AddText("Item", Enums::GetAnimation(m->Read(0x0)));
		}
		m->AddText("horizontalRotate", Enums::GetHorRotate(m->Read(0x14)));
		m->AddFloat("maxHeadAngleToDown", 0x18);
		m->AddFloat("maxHeadAngleToSide", 0x1C);
		m->AddFloat("maxHeadAngleToUp", 0x20);
		m->AddSource("targetBoneName", 0x24);
		m->AddFloat("trackingTimeOut", 0x30);
		m->AddSFX("turnSound", 0x34);
		m->AddText("verticalRotate", Enums::GetHorRotate(m->Read(0x50)));
		m->AddBool("ingnoreRotateToTarget", 0x54);
		m->AddBool("noRotateBody", 0x55);
		m->AddBool("esu", 0x56);
		m->AddBool("useInEveryAnimation", 0x57);
		m->AddBool("useOnlyAddedAnimations", 0x58);
	}
	AddFloat("turnSpeedModifier", 0xB4);
	AddFloat("walk", 0xB8);
	AddFloat("walkBackwards", 0xBC);
	AddFloat("walkForward", 0xC0);
	AddBool("canWalkBackwards", 0xC4);
	AddBool("finishMoveAnimation", 0xC5);
	AddBool("forceMoveDisableUsed", 0xC6);
	AddBool("groundNormalByBoundingBox", 0xC7);
	AddBool("moveAnimationsNoScale", 0xC8);
	AddBool("useWalkForward", 0xC9);
}
