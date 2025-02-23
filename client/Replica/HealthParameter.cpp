#include "HealthParameter.h"

HealthParameter::HealthParameter(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.HealthParameter");
	Init();
}

HealthParameter::~HealthParameter()
{
}

void HealthParameter::Init()
{
}