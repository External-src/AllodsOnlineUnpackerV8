#include "SkyMesh.h"

SkyMesh::SkyMesh(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

SkyMesh::~SkyMesh()
{
}

void SkyMesh::Init()
{
	AddFloat("noiseFactor", 0x18);
	FORCON("parts", 0x1C, 0xAC)
	{
		m->AddInt("ambientColor", 0x4);
		m->AddHref("animation", 0x8);
		OPENEX_X("color0", 0x10)
		{
			m->AddInt("GradientSkyHi", 0x4);
			m->AddInt("GradientSkyLo", 0x8);
			m->AddInt("GradientSunHi", 0x0C);
			m->AddInt("GradientSunLo", 0x10);
			m->AddFloat("facingValueSky", 0x14);
			m->AddFloat("facingValueSun", 0x18);
		}
		OPENEX_X("color1", 0x2C)
		{
			m->AddInt("GradientSkyHi", 0x4);
			m->AddInt("GradientSkyLo", 0x8);
			m->AddInt("GradientSunHi", 0x0C);
			m->AddInt("GradientSunLo", 0x10);
			m->AddFloat("facingValueSky", 0x14);
			m->AddFloat("facingValueSun", 0x18);
		}
		OPENEX_X("color2", 0x48)
		{
			m->AddInt("GradientSkyHi", 0x4);
			m->AddInt("GradientSkyLo", 0x8);
			m->AddInt("GradientSunHi", 0x0C);
			m->AddInt("GradientSunLo", 0x10);
			m->AddFloat("facingValueSky", 0x14);
			m->AddFloat("facingValueSun", 0x18);
		}
		m->AddFloat("colorFactor", 0x64);
		FORCONX("controllers", 0x68, 0x18)
		{
			m->AddHref("animation", 0x4);
			m->AddHref("controller", 0x0C);
			m->AddFloat("speed", 0x14);
		}
		FORNOTX("effects", 0x78, 0x4)
		{
			m->OpenCon("Item", i);
		}
		m->AddFloat("fovFactor", 0x88);
		m->AddHref("geometry", 0x8C);
		m->AddFloat("shift", 0x94);
		m->AddVector3("worldCoord", 0x98);
		m->AddFloat("yaw", 0xA4);
		m->AddBool("show", 0xA8);
		m->AddBool("useWorldCoord", 0xA9);
	}
	AddFloat("shift", 0x2C);
	AddFloat("yaw", 0x30);
}