#include "ParticleAnimation.h"

ParticleAnimation::ParticleAnimation(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

ParticleAnimation::~ParticleAnimation()
{
}

void ParticleAnimation::Init()
{
	FORCON("ParticleEmitters", 0x18, 0x40)
	{
		m->AddText("BlendEffect", Enums::GetBBlendEffect(m->Read(0x4)));
		m->AddInt("Color", 0x8);
		m->AddText("RenderEffect", Enums::GetRenderEffect(m->Read(0x0C)));
		m->AddFloat("ambientLightFactor", 0x10);
		m->OpenCon("colorDescriptor", 0x14);
		m->AddText("decalMirrorMode", Enums::GetMirrorMode(m->Read(0x18)));
		m->AddFloat("fogFactor", 0x1C);
		m->AddSource("name", 0x20);
		m->AddFloat("pivotX", 0x2C);
		m->AddFloat("pivotY", 0x30);
		m->AddFloat("virtualOffset", 0x34);
		m->AddBool("UseLooping", 0x38);
		m->AddBool("WorldSpaceEmitter", 0x39);
		m->AddBool("decalEmitter", 0x3A);
		m->AddBool("decalInheritRotation", 0x3B);
		m->AddBool("distortionEmitter", 0x3C);
		m->AddBool("texFlipX", 0x3D);
		m->AddBool("texFlipY", 0x3E);
		m->AddBool("useScaleForVirtualOffset", 0x3F);
	}
	AddAABB("aabb", 0x28);
	OPENEX("animation", 0x40)
	{
		m->AddInt("localID", 0x4);
		m->AddInt("size", 0x8);
	}
	AddBinFile("binaryFile", 0x4C);
	OPENEX("decal", 0x60)
	{
		m->AddInt("decalColor", 0x4);
		m->AddText("decalMirrorMode", Enums::GetMirrorMode(m->Read(0x8)));
		m->AddFloat("decalRotation", 0x0C);
		m->AddFloat("decalSize", 0x10);
		m->AddHref("decalTexture", 0x14);
		m->AddBool("decalInheritRotation", 0x1C);
	}
	AddInt("endFrame", 0x80);
	OPENEX("fade", 0x84)
	{
		m->AddFloat("beginFadeDistance", 0x4);
		m->AddFloat("endFadeDistance", 0x8);
	}
	AddInt("loopFrame", 0x90);
	AddFloat("scaleDistanceEnd", 0x94);
	AddFloat("scaleDistanceStart", 0x98);
	FORNOT("singleTextures", 0x9C, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddFloat("speed", 0xAC);
	AddHref("texture", 0xB0);
	OPENEX("textureAtlasParameters", 0xB8)
	{
		m->AddFloat("delay", 0x4);
		m->AddInt("endFrame", 0x8);
		m->AddFloat("lifetime", 0x0C);
		m->AddFloat("speed", 0x10);
		m->AddInt("startFrame", 0x14);
		m->AddHref("textureAtlas", 0x18);
		m->AddBool("loop", 0x20);
		m->AddBool("useRandomFrame", 0x21);
	}
	FORNOT("textures", 0xDC, 0x8)
	{
		m->AddHref("Item", i);
	}
	AddBool("looped", 0xEC);
}