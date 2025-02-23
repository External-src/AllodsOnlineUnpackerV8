#include "PositionSynchronizer.h"

PositionSynchronizer::PositionSynchronizer(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.PositionSynchronizer");
	Init();
}

PositionSynchronizer::~PositionSynchronizer()
{
}

void PositionSynchronizer::Init()
{
	AddVector3("shift", 0x18);
}