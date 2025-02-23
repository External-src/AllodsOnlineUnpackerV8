#include "HaloRankParameter.h"

HaloRankParameter::HaloRankParameter(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.HaloRankParameter");
	Init();
}

HaloRankParameter::~HaloRankParameter()
{
}

void HaloRankParameter::Init()
{
}