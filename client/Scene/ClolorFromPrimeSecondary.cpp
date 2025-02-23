#include "ClolorFromPrimeSecondary.h"

ClolorFromPrimeSecondary::ClolorFromPrimeSecondary(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Scene.ClolorFromPrimeSecondary");
	Init();
}

ClolorFromPrimeSecondary::~ClolorFromPrimeSecondary()
{
}

void ClolorFromPrimeSecondary::Init()
{
	AddText("use", Enums::GetUseSt(Read(0x18)));
}