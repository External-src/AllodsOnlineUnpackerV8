#include "ThreatParameter.h"

ThreatParameter::ThreatParameter(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.ThreatParameter");
	Init();
}

ThreatParameter::~ThreatParameter()
{
}

void ThreatParameter::Init()
{
}