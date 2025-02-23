#include "RankInGuildParameter.h"

RankInGuildParameter::RankInGuildParameter(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.RankInGuildParameter");
	Init();
}

RankInGuildParameter::~RankInGuildParameter()
{
}

void RankInGuildParameter::Init()
{
}