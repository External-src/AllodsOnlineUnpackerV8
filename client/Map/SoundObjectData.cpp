#include "SoundObjectData.h"

SoundObjectData::SoundObjectData(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Map.SoundObjectData");
	Init();
}

SoundObjectData::~SoundObjectData()
{
}

void SoundObjectData::Init()
{
	AddFloat("MaxRadiusScale", 0x18);
	AddFloat("MinRadiusScale", 0x1C);
	AddFloat("Volume", 0x20);
}