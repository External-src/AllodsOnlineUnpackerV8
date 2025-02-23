#include "DayTimeParameter.h"

DayTimeParameter::DayTimeParameter(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.DayTimeParameter");
	Init();
}

DayTimeParameter::~DayTimeParameter()
{
}

void DayTimeParameter::Init()
{
}