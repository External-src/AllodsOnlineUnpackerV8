#include "VICReplaceTexture.h"

VICReplaceTexture::VICReplaceTexture(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.VisualConstructor.VICReplaceTexture");
	Init();
}

VICReplaceTexture::~VICReplaceTexture()
{
}

void VICReplaceTexture::Init()
{
	FORNOT("shapeName", 0x1C, 0x0C)
	{
		m->AddSource("Item", i);
	}
	AddHref("texture", 0x2C);
}