#include "LevelParameter.h"

LevelParameter::LevelParameter(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.LevelParameter");
	Init();
}

LevelParameter::~LevelParameter()
{
}

void LevelParameter::Init()
{
}