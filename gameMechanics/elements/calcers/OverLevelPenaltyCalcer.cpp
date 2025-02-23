#include "OverLevelPenaltyCalcer.h"

OverLevelPenaltyCalcer::OverLevelPenaltyCalcer(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "gameMechanics.elements.calcers.OverLevelPenaltyCalcer");
	Init();
}

OverLevelPenaltyCalcer::~OverLevelPenaltyCalcer()
{
}

void OverLevelPenaltyCalcer::Init()
{
	AddFloat("exponent", 0x18);
	AddInt("level", 0x1C);
	AddFloat("multiplier", 0x20);
}