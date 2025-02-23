#include "WeatherCreatureVisAction.h"

WeatherCreatureVisAction::WeatherCreatureVisAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.WeatherCreatureVisAction");
	Init();
}

WeatherCreatureVisAction::~WeatherCreatureVisAction()
{
}

void WeatherCreatureVisAction::Init()
{
	AddSource("visActionID", 0x14);
	OPENEX("params", 0x24)
	{
		m->AddText("ambientSoundImpact", Enums::GetAmbientImpact(m->Read(0x4)));
		m->AddHref("areaEffect", 0x8);
		m->AddFloat("fadeTime", 0x10);
		OPENEX_X("light", 0x14)
		{
			m->AddInt("AmbientColor", 0x4);
			m->AddFloat("AmbientFactor", 0x8);
			m->AddInt("ContourColor", 0x0C);
			m->AddInt("DiffuseColor", 0x10);
			m->AddFloat("FadeEnd", 0x14);
			m->AddFloat("FadeStart", 0x18);
			m->AddInt("FogColor", 0x1C);
			m->AddFloat("FogEnd", 0x20);
			m->AddFloat("FogStart", 0x24);
			m->AddInt("GrassContourColorMultiplier", 0x28);
			m->AddInt("PointLightColor", 0x2C);
			m->AddInt("SelfIllumColor", 0x30);
			m->AddInt("SpecularColor", 0x34);
			m->AddInt("SpecularWaterColor", 0x38);
			m->AddFloat("SunLightPitch", 0x3C);
			m->AddFloat("SunLightYaw", 0x40);
			m->AddInt("TerrainContourColor", 0x44);
			m->AddFloat("TerrainContourPower", 0x48);
			m->AddInt("TerrainSpecularColor", 0x4C);
			m->AddInt("WaterGradientEnd", 0x50);
			m->AddInt("WaterGradientStart", 0x54);
			m->AddHref("animatedAmbientColor", 0x58);
			m->AddHref("animatedDiffuseColor", 0x60);
			m->AddHref("animatedPointLightColor", 0x68);
			m->AddHref("animatedSelfIllumColor", 0x70);
			m->AddFloat("desaturation", 0x78);
			m->AddInt("minAmbientOcclusionValue", 0x7C);
			m->AddFloat("objectsLightmapBias", 0x80);
			m->AddFloat("terrainLightmapBias", 0x84);
		}
		m->AddHref("postEffectParams", 0x9C);
		m->AddText("priority", Enums::GetPriority(m->Read(0xA4)));
		m->AddHref("skyMesh", 0xA8);
		m->AddHref("weatherType", 0xB0);
		m->AddBool("hasLight", 0xB8);
		m->AddBool("playInBuildings", 0xB9);
	}
}