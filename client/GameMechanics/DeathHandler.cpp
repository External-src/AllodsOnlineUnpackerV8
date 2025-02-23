#include "DeathHandler.h"

DeathHandler::DeathHandler(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.GameMechanics.DeathHandler");
	Init();
}

DeathHandler::~DeathHandler()
{
}

void DeathHandler::Init()
{
	OpenCon("deathScript", 0x18);
	AddBool("useParentState", 0x1C);
}