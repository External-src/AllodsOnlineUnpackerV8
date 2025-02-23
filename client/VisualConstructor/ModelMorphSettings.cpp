#include "ModelMorphSettings.h"

ModelMorphSettings::ModelMorphSettings(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

ModelMorphSettings::~ModelMorphSettings()
{
}

void ModelMorphSettings::Init()
{
	FORCON("controls", 0x18, 0x20)
	{
		FORCONX("bones", 0x4, 0x1C)
		{
			m->AddSource("boneName", 0x4);
			m->AddVector3("power", 0x10);
		}
		m->AddText("controlName", Enums::GetModelMorphControlName(m->Read(0x14)));
		m->AddFloat("maxVal", 0x18);
		m->AddFloat("minVal", 0x1C);
	}
	FORCON("presets", 0x28, 0x18)
	{
		FORCONX("values", 0x8, 0x10)
		{
			m->AddText("controlName", Enums::GetModelMorphControlName(m->Read(0x8)));
			m->AddFloat("value", 0x0C);
		}
	}
}