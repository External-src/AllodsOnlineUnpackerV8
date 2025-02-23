#include "Geometry.h"

Geometry::Geometry(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\" "));
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

Geometry::~Geometry()
{
}

void Geometry::Init()
{
	AddHref("SkeletalAnimation", 0x18);
	AddAABB("aabb", 0x20);
	FORCON("areaFragments", 0x38, 0x60)
	{
		m->AddAABB("aabb", 0x4);
		m->AddInt("areaId", 0x1C);
		m->OpenCon("areaInfo", 0x20);
		OPENEX_X("blob", 0x24)
		{
			m->AddInt("localID", 0x4);
			m->AddInt("size", 0x8);
		}
		FORCONX("edges", 0x30, 0x1C)
		{
			m->AddVector3("beg", 0x4);
			m->AddVector3("end", 0x10);
		}
		m->AddSource("name", 0x40);
		FORNOTX("portals", 0x4C, 0x4)
		{
			m->AddInt("Item", 0x0);
		}
		m->AddBool("useOcclusionTest", 0x5C);
	}
	AddHref("attributeAnimation", 0x48);
	//string path = GetPatch();
	//int st = path.rfind('.');
	//if (st != string::npos)
	//{
	//	path.erase(st + 1, 3);
	//	path += "bin";
	////	AddBinSize(path);
	//	OPENEX("binaryFile", 0x50)
	//	{
	//		m->AddAttribute("href", "/" + path);
	//	}
	//}
	AddBinFile("binaryFile", 0x50);
	AddFloat("decalTraceHeight", 0x64);
	AddFloat("fadeDistanceEnd", 0x68);
	AddFloat("fadeDistanceStart", 0x6C);
	FORCON("flareInfos", 0x70, 0x18)
	{
		m->AddHref("flareEffect", 0x4);
		m->AddSource("locatorName", 0x0C);
	}
	AddFloat("fogFactor", 0x80);
	AddAABB("geometryBox", 0x84);
	FORCON("geometryFragments", 0x9C, 0x28)
	{
		m->AddAABB("aabb", 0x4);
		OPENEX_X("blob", 0x1C)
		{
			m->AddInt("localID", 0x4);
			m->AddInt("size", 0x8);
		}
	}
	AddInt("globalID", 0xAC);
	AddText("hideRule", Enums::GetHRule(Read(0xB0)));
	OPENEX("indexBuffer", 0xB4)
	{
		m->AddInt("localID", 0x4);
		m->AddInt("size", 0x8);
	}
	FORCON("joints", 0xC0, 0x18)
	{
		m->AddInt("id", 0x4);
		m->AddSource("name", 0x8);
		m->AddFloat("scale", 0x14);
	}
	FORNOT("lodDistances", 0xD0, 0x4)
	{
		m->AddFloat("Item", i);
	}
	AddFloat("lodFactor", 0xE0);
	FORCON("modelElements", 0xE4, 0x78)
	{
		if (m->Read(0x24 + 0x8) == NULL)
			continue;

		FORCONX("linkedElements", 0x4, 0x0C)
		{
			m->AddSource("Item", 0x0);
		}
		FORCONX("lods", 0x14, 0x14)
		{
			m->AddInt("indexBufferBegin", 0x4);
			m->AddInt("indexBufferEnd", 0x8);
			m->AddInt("vertexBufferBegin", 0x0C);
			m->AddInt("vertexBufferEnd", 0x10);
		}
		OPENEX_X("material", 0x24)
		{
			m->AddText("BlendEffect", Enums::GetBlendEffect(m->Read(0x4)));
			m->AddHref("diffuseTexture", 0x8);
			m->OpenCon("params", 0x10);
			m->AddFloat("transparencyModifier", 0x14);
			m->AddFloat("uTranslateSpeed", 0x18);
			m->AddFloat("vTranslateSpeed", 0x1C);
			m->AddBool("scrollAlpha", 0x20);
			m->AddBool("scrollRGB", 0x21);
			m->AddBool("transparencyModifierIgnoreDiffuseAlpha", 0x22);
			m->AddBool("transparent", 0x23);
			m->AddBool("useFog", 0x24);
			m->AddBool("useModifiers", 0x25);
			m->AddBool("visible", 0x26);
		}
		m->AddSource("materialName", 0x4C);
		m->AddSource("name", 0x58);
		m->AddInt("skinIndex", 0x64);
		m->AddInt("vertexBufferOffset", 0x68);
		m->AddInt("vertexDeclarationID", 0x6C);
		m->AddFloat("virtualOffset", 0x70);
		m->AddBool("outliningEnabled", 0x74);
		m->AddBool("useScaleForVirtualOffset", 0x75);
	}
	FORCON("occluderInfos", 0xF4, 0x3C)
	{
		m->AddAABB("aabb", 0x4);
		m->AddVector3("center", 0x1C);
		m->AddVector2("x", 0x28);
		m->AddVector2("y", 0x30);
		m->AddFloat("z", 0x38);
	}
	AddText("orientationMode", Enums::GetOrientation(Read(0x104)));
	FORCON("parts", 0x108, 0x44)
	{
		m->AddAABB("aabb", 0x4);
		m->AddInt("endElement", 0x1C);
		FORNOTX("implicitAreas", 0x20, 0x0C)
		{
			m->AddSource("Item", i);
		}
		m->AddSource("name", 0x30);
		m->AddInt("startElement", 0x3C);
		m->AddBool("areaPart", 0x40);
	}
	FORCON("portalFragments", 0x118, 0x4C)
	{
		m->AddAABB("aabb", 0x4);
		OPENEX_X("blob", 0x1C)
		{
			m->AddInt("localID", 0x4);
			m->AddInt("size", 0x8);
		}
		FORCONX("edges", 0x28, 0x1C)
		{
			m->AddVector3("beg", 0x4);
			m->AddVector3("end", 0x10);
		}
		m->AddInt("leftArea", 0x38);
		m->AddVector3("normal", 0x3C);
		m->AddInt("rightArea", 0x48);
	}
	OpenCon("rootMaterial", 0x128);
	AddFloat("scaleDistanceEnd", 0x12C);
	AddFloat("scaleDistanceStart", 0x130);
	FORCON("sceneNodes", 0x134, 0x30)
	{
		m->AddSource("name", 0x4);
		m->AddRotation3("rotation", 0x1C);
		m->AddVector3("position", 0x10);
		m->AddFloat("scale", 0x2C);
	}
	AddHref("shadowSettings", 0x144);
	OPENEX("skeleton", 0x14C)
	{
		m->AddInt("localID", 0x4);
		m->AddInt("size", 0x8);
	}
	AddFloat("softFadeFactor", 0x158);
	AddText("sortMode", Enums::GetSortMode(Read(0x15C)));
	AddInt("version", 0x160);
	OPENEX("vertexBuffer", 0x164)
	{
		m->AddInt("localID", 0x4);
		m->AddInt("size", 0x8);
	}
	FORCON("vertexDeclarations", 0x170, 0x74)
	{
		OPENEX_X("bitangent", 0x4)
		{
			m->AddInt("offset", 0x4);
			m->AddText("type", Enums::GetTypeGeom(m->Read(0x8)));
		}
		OPENEX_X("color", 0x10)
		{
			m->AddInt("offset", 0x4);
			m->AddText("type", Enums::GetTypeGeom(m->Read(0x8)));
		}
		OPENEX_X("indices", 0x1C)
		{
			m->AddInt("offset", 0x4);
			m->AddText("type", Enums::GetTypeGeom(m->Read(0x8)));
		}
		OPENEX_X("normal", 0x28)
		{
			m->AddInt("offset", 0x4);
			m->AddText("type", Enums::GetTypeGeom(m->Read(0x8)));
		}
		OPENEX_X("position", 0x34)
		{
			m->AddInt("offset", 0x4);
			m->AddText("type", Enums::GetTypeGeom(m->Read(0x8)));
		}
		m->AddInt("stride", 0x40);
		OPENEX_X("tangent", 0x44)
		{
			m->AddInt("offset", 0x4);
			m->AddText("type", Enums::GetTypeGeom(m->Read(0x8)));
		}
		OPENEX_X("texcoord0", 0x50)
		{
			m->AddInt("offset", 0x4);
			m->AddText("type", Enums::GetTypeGeom(m->Read(0x8)));
		}
		OPENEX_X("texcoord1", 0x5C)
		{
			m->AddInt("offset", 0x4);
			m->AddText("type", Enums::GetTypeGeom(m->Read(0x8)));
		}
		OPENEX_X("weights", 0x68)
		{
			m->AddInt("offset", 0x4);
			m->AddText("type", Enums::GetTypeGeom(m->Read(0x8)));
		}
	}
	AddInt("visualSkeletonSize", 0x180);
	AddBool("absoluteDistanceFade", 0x184);
	AddBool("castShadows", 0x185);
	AddBool("decalModel", 0x186);
	AddBool("enableDistanceFade", 0x187);
	AddBool("exportDefaultAnimation", 0x188);
	AddBool("fadeByCameraCollision", 0x189);
	AddBool("ignoreFadeDistanceFactor", 0x18A);
	AddBool("ignoreZ", 0x18B);
	AddBool("largeModel", 0x18C);
	AddBool("lodModel", 0x18D);
	AddBool("portalModel", 0x18E);
	AddBool("useColors", 0x18F);
	AddBool("useDecals", 0x190);
	AddBool("useProceduralEffect", 0x191);
	AddBool("vb32", 0x192);
}