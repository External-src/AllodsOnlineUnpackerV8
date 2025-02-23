#include "ZoneInfo.h"

ZoneInfo::ZoneInfo(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Map.ZoneInfo");
	Init();
}


ZoneInfo::~ZoneInfo()
{
}

void ZoneInfo::Init()
{
	OPENEX("ambience", 0x1C)
	{
		m->AddSource("name", 0x4);
		m->AddHref("project", 0x10);
	}
	FORCON("ambienceParameters", 0x34, 0x10)
	{
//		printf("%X\n", main);
//		system("pause");
		m->AddHref("parameter", 0x4);
		m->AddFloat("value", 0x0C);
	}
	AddInt("ambienceTimeout", 0x44);
	AddFloat("hiCutFreq", 0x48);
	AddHref("lights", 0x4C);
	OPENEX("music", 0x54)
	{
		m->AddSource("name", 0x4);
		m->AddHref("project", 0x10);
	}
	OPENEX("reverbPreset", 0x6C)
	{
		m->AddSource("name", 0x4);
		m->AddHref("project", 0x10);
	}
}
