#include "ZoneLights.h"

ZoneLights::ZoneLights(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

ZoneLights::~ZoneLights()
{
}

void ZoneLights::Init()
{
	OPENEX("bloomSettings", 0x18)
	{
		m->AddFloat("bloomContrastPower", 0x4);
		m->AddFloat("bloomContrastThreshold", 0x8);
		m->AddFloat("bloomContribution", 0x0C);
		m->AddBool("enable", 0x10);
	}
	OPENEX("colorGradingSettings", 0x2C)
	{
		m->AddHref("lutTexture", 0x4);
	}
	OPENEX("defaultLight", 0x38)
	{
		m->AddHref("areaEffect", 0x4);
		OPENEX_X("colorGradingSettings", 0x0C)
		{
			m->AddHref("lutTexture", 0x4);
		}
		OPENEX_X("light", 0x18)
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
		m->AddHref("postEffectParams", 0xA0);
		OPENEX_X("posteffectFogSettings", 0xA8)
		{
			m->AddFloat("brightness", 0x4);
			m->AddInt("color", 0x8);
			m->AddFloat("densityDown", 0x0C);
			m->AddFloat("densityUp", 0x10);
			OPENEX_X("distanceSettings", 0x14)
			{
				m->AddFloat("falloff", 0x4);
				m->AddFloat("maxDistance", 0x8);
				m->AddFloat("minDistance", 0x0C);
			}
			OPENEX_X("heightSettingsDown", 0x24)
			{
				m->AddFloat("falloff", 0x4);
				m->AddFloat("maxHeight", 0x8);
				m->AddFloat("minHeight", 0x0C);
			}
			OPENEX_X("heightSettingsUp", 0x34)
			{
				m->AddFloat("falloff", 0x4);
				m->AddFloat("maxHeight", 0x8);
				m->AddFloat("minHeight", 0x0C);
			}
			OPENEX_X("sunSettings", 0x44)
			{
				m->AddFloat("brightness", 0x4);
			}
			m->AddBool("use", 0x4C);
		}
		m->AddHref("skyMesh", 0xF8);
		m->AddFloat("time", 0x100);
	}
	AddInt("index", 0x13C);
	FORCON("instantLights", 0x140, 0x104)
	{
		m->AddHref("areaEffect", 0x4);
		OPENEX_X("colorGradingSettings", 0x0C)
		{
			m->AddHref("lutTexture", 0x4);
		}
		OPENEX_X("light", 0x18)
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
		m->AddHref("postEffectParams", 0xA0);
		OPENEX_X("posteffectFogSettings", 0xA8)
		{
			m->AddFloat("brightness", 0x4);
			m->AddInt("color", 0x8);
			m->AddFloat("densityDown", 0x0C);
			m->AddFloat("densityUp", 0x10);
			OPENEX_X("distanceSettings", 0x14)
			{
				m->AddFloat("falloff", 0x4);
				m->AddFloat("maxDistance", 0x8);
				m->AddFloat("minDistance", 0x0C);
			}
			OPENEX_X("heightSettingsDown", 0x24)
			{
				m->AddFloat("falloff", 0x4);
				m->AddFloat("maxHeight", 0x8);
				m->AddFloat("minHeight", 0x0C);
			}
			OPENEX_X("heightSettingsUp", 0x34)
			{
				m->AddFloat("falloff", 0x4);
				m->AddFloat("maxHeight", 0x8);
				m->AddFloat("minHeight", 0x0C);
			}
			OPENEX_X("sunSettings", 0x44)
			{
				m->AddFloat("brightness", 0x4);
			}
			m->AddBool("use", 0x4C);
		}
		m->AddHref("skyMesh", 0xF8);
		m->AddFloat("time", 0x100);
	}
	FORCON("randomLights", 0x150, 0x130)
	{
		m->AddText("ambientSoundImpact", Enums::GetSoundImpact(m->Read(0x4)));
		m->AddFloat("fadeInSeconds", 0x8);
		m->AddFloat("fadeOutSeconds", 0x0C);
		OPENEX_X("light", 0x10)
		{
			m->AddHref("areaEffect", 0x4);
			OPENEX_X("colorGradingSettings", 0x0C)
			{
				m->AddHref("lutTexture", 0x4);
			}
			OPENEX_X("light", 0x18)
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
			m->AddHref("postEffectParams", 0xA0);
			OPENEX_X("posteffectFogSettings", 0xA8)
			{
				m->AddFloat("brightness", 0x4);
				m->AddInt("color", 0x8);
				m->AddFloat("densityDown", 0x0C);
				m->AddFloat("densityUp", 0x10);
				OPENEX_X("distanceSettings", 0x14)
				{
					m->AddFloat("falloff", 0x4);
					m->AddFloat("maxDistance", 0x8);
					m->AddFloat("minDistance", 0x0C);
				}
				OPENEX_X("heightSettingsDown", 0x24)
				{
					m->AddFloat("falloff", 0x4);
					m->AddFloat("maxHeight", 0x8);
					m->AddFloat("minHeight", 0x0C);
				}
				OPENEX_X("heightSettingsUp", 0x34)
				{
					m->AddFloat("falloff", 0x4);
					m->AddFloat("maxHeight", 0x8);
					m->AddFloat("minHeight", 0x0C);
				}
				OPENEX_X("sunSettings", 0x44)
				{
					m->AddFloat("brightness", 0x4);
				}
				m->AddBool("use", 0x4C);
			}
			m->AddHref("skyMesh", 0xF8);
			m->AddFloat("time", 0x100);
		}
		m->AddFloat("maxDuration", 0x114);
		m->AddFloat("maxStartTime", 0x118);
		m->AddFloat("minDuration", 0x11C);
		m->AddFloat("minStartTime", 0x120);
		m->AddFloat("probability", 0x124);
		m->AddHref("weatherType", 0x128);
	}
	AddHref("waterLight", 0x160);
	AddFloat("waterReflectionCoefficient", 0x168);
	AddBool("fogUsesQualitySettings", 0x16C);
	AddBool("hiQualitySky", 0x16D);
	AddBool("renderSky", 0x16E);
}