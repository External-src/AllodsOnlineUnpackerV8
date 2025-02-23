#include "VisCharacterTemplate.h"

VisCharacterTemplate::VisCharacterTemplate(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\" "));
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

VisCharacterTemplate::~VisCharacterTemplate()
{
}

void VisCharacterTemplate::Init()
{
	FORCON("additionalPortraitSettings", 0x18, 0x3C)
	{
		m->AddSource("name", 0x4);
		OPENEX_X("portraitSettings", 0x10)
		{
			m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
			m->AddInt("animationTime", 0x8);
			m->AddVector3("cameraAnchor", 0x0C);
			m->AddRotation3("cameraRotation", 0x18);
			m->AddFloat("projSettingsVWidth", 0x28);
		}
	}
	AddSFX("agroSound", 0x28);
	AddHref("animationKeysAction", 0x44);
	AddHref("animationKeysActionPeriod", 0x4C);
	AddHref("animationKeysSound", 0x54);
	AddHref("animationProperties", 0x5C);
	AddHref("characterVisObject", 0x64);
	OPENEX("creatureParameters", 0x6C)
	{
		m->AddBool("disableProceduralAndColorEffects", 0x4);
	}
	AddHref("defaultDress", 0x74);
	AddHref("defaultSoundVariation", 0x7C);
	AddHref("extension", 0x84);
	AddText("gender", Enums::GetGender(Read(0x8C)));
	FORNOT("hairColoredGeosets", 0x90, 0x0C)
	{
		m->AddSource("Item", i);
	}
	AddFloat("height", 0xA0);
	AddSource("helmGeoset", 0xA4);
	AddInt("hitAnimationCooldown", 0xB0);
	AddInt("hitCritAnimationCooldown", 0xB4);
	AddHref("hitCriticalEffects", 0xB8);
	AddHref("hitEffects", 0xC0);
	AddHref("lower", 0xC8);
	AddHref("mainBakedTexture", 0xD0);
	AddHref("mainHand", 0xD8);
	AddFloat("massCoefficient", 0xE0);
	OpenCon("meleeAttack", 0xE4);
	AddHref("mobAnimations", 0xE8);
	AddHref("morphSettings", 0xF0);
	AddSFX("moveSFX", 0xF8);
	AddHref("offHand", 0x114);
	OPENEX("portraitSettings", 0x11C)
	{
		m->AddText("animation", Enums::GetAnimation(m->Read(0x4)));
		m->AddInt("animationTime", 0x8);
		m->AddVector3("cameraAnchor", 0x0C);
		m->AddRotation3("cameraRotation", 0x18);
		m->AddFloat("projSettingsVWidth", 0x28);
	}
	AddSFX("preAggroSound", 0x148);
	AddFloat("radius", 0x164);
	AddHref("sfxArmorSet", 0x168);
	FORCON("specialControllers", 0x170, 0x2C)
	{
		m->AddHref("controller", 0x4);
		m->AddSource("name", 0x0C);
		m->OpenCon("parentController", 0x18);
	}
	FORCON("specialHairTexPatch", 0x180, 0x20)
	{
		OPENEX_X("rectangle", 0x4)
		{
			m->AddFloat("x1", 0x4);
			m->AddFloat("y1", 0x0C);
			m->AddFloat("x2", 0x8);
			m->AddFloat("y2", 0x10);
		}
		m->AddHref("texture", 0x18);
	}
	AddHref("traceProperties", 0x190);
	OPENEX("uiSceneSettings", 0x198)
	{
		m->AddVector3("cameraAnchor", 0x4);
		m->AddFloat("cameraBodyAnchorCoeff", 0x10);
		m->AddFloat("preMissionAdditionalAway", 0x14);
		m->AddVector3("preMissionFaceCameraAnchor", 0x18);
		m->AddFloat("scale", 0x24);
	}
	AddFloat("uiSelectionScale", 0x1C0);
	AddHref("underwear", 0x1C4);
	AddHref("upper", 0x1CC);
	AddHref("variations", 0x1D4);
	OPENEX("visualAliases", 0x1DC)
	{
		FORCONX("creatureVisActions", 0x18, 0x14)
		{
			m->AddHref("alias", 0x4);
			m->AddHref("resource", 0x0C);
		}
		FORCONX("visualItems", 0x28, 0x14)
		{
			m->AddHref("alias", 0x4);
			m->AddHref("resource", 0x0C);
		}
		FORCONX("visualMounts", 0x38, 0x14)
		{
			m->AddHref("alias", 0x4);
			m->AddHref("resource", 0x0C);
		}
	}
	OpenCon("visualScript", 0x224);
	AddSFX("weaponSound", 0x228);
	AddBool("disableCorpseThrowing", 0x244);
	AddBool("isBreathe", 0x245);
	AddBool("showDecal", 0x246);
	AddBool("useMobAnimationsSet", 0x247);
	AddBool("useWeaponItemsAnimations", 0x248);
}
