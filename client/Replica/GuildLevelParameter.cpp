#include "GuildLevelParameter.h"

GuildLevelParameter::GuildLevelParameter(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.GuildLevelParameter");
	Init();
}

GuildLevelParameter::~GuildLevelParameter()
{
}

void GuildLevelParameter::Init()
{
}