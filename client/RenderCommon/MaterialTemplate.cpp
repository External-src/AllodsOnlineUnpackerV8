#include "MaterialTemplate.h"

MaterialTemplate::MaterialTemplate(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

MaterialTemplate::~MaterialTemplate()
{
}

void MaterialTemplate::Init()
{
	AddBinFile("binaryFile", 0x18);
	AddInt("binaryFileSize", 0x2C);
	AddHref("fallback", 0x30);
	OPENEX("pixelShader", 0x38)
	{
		FORCON("defines", 0x4, 0x1C)
		{
			m->AddSource("name", 0x4);
			m->AddSource("value", 0x10);
		}
		m->AddSource("entry", 0x14);
		FORNOT("profiles", 0x20, 0x0C)
		{
			m->AddSource("Item", i);
		}
		FORNOT("shaderIndices", 0x30, 0x4)
		{
			m->AddInt("Item", i);
		}
		FORCON("shaderStruct", 0x40, 0x20)
		{
			OPENEX_X("blob", 0x4)
			{
				m->AddInt("localID", 0x4);
				m->AddInt("size", 0x8);
			}
			FORCON("colorVars", 0x10, 0x14)
			{
				m->AddSource("name", 0x4);
				m->AddInt("registerHW", 0x10);
			}
		}
		FORCON("switches", 0x50, 0x20)
		{
			m->AddInt("hiValue", 0x4);
			m->AddInt("loValue", 0x8);
			m->AddSource("name", 0x0C);
			m->AddInt("slice", 0x18);
			m->AddBool("useUI", 0x1C);
		}
	}
	OPENEX("vertexShader", 0x98)
	{
		FORCON("defines", 0x4, 0x1C)
		{
			m->AddSource("name", 0x4);
			m->AddSource("value", 0x10);
		}
		m->AddSource("entry", 0x14);
		FORNOT("profiles", 0x20, 0x0C)
		{
			m->AddSource("Item", i);
		}
		FORNOT("shaderIndices", 0x30, 0x4)
		{
			m->AddInt("Item", i);
		}
		FORCON("shaderStruct", 0x40, 0x20)
		{
			OPENEX_X("blob", 0x4)
			{
				m->AddInt("localID", 0x4);
				m->AddInt("size", 0x8);
			}
			FORCON("colorVars", 0x10, 0x14)
			{
				m->AddSource("name", 0x4);
				m->AddInt("registerHW", 0x10);
			}
		}
		FORCON("switches", 0x50, 0x20)
		{
			m->AddInt("hiValue", 0x4);
			m->AddInt("loValue", 0x8);
			m->AddSource("name", 0x0C);
			m->AddInt("slice", 0x18);
			m->AddBool("useUI", 0x1C);
		}
	}
}