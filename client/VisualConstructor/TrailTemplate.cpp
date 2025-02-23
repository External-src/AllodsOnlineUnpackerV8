#include "TrailTemplate.h"

TrailTemplate::TrailTemplate(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

TrailTemplate::~TrailTemplate()
{
}

void TrailTemplate::Init()
{
	AddInt("color", 0x18);
	OpenCon("colorDescriptor", 0x1C);
	AddInt("decayTime", 0x20);
	AddInt("fadeInTimeMSec", 0x24);
	AddInt("fadeOutTimeMSec", 0x28);
	AddFloat("speedEnd", 0x2C);
	AddFloat("speedStart", 0x30);
	AddFloat("stretchSpeed", 0x34);
	AddInt("texCoordsPeriodMs", 0x38);
	AddHref("trailTexture", 0x3C);
}