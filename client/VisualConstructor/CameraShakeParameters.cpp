#include "CameraShakeParameters.h"

CameraShakeParameters::CameraShakeParameters(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

CameraShakeParameters::~CameraShakeParameters()
{
}

void CameraShakeParameters::Init()
{
	AddFloat("amplitudeScale", 0x18);
	AddHref("animation", 0x1C);
	AddFloat("maxRadius", 0x24);
	AddFloat("minRadius", 0x28);
	AddFloat("timeScale", 0x2C);
	AddBool("looped", 0x30);
}