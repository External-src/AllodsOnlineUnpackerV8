#include "PredicateCreatureFlagAction.h"

PredicateCreatureFlagAction::PredicateCreatureFlagAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.PredicateCreatureFlagAction");
	Init();
}

PredicateCreatureFlagAction::~PredicateCreatureFlagAction()
{
}

void PredicateCreatureFlagAction::Init()
{
	AddSource("visActionID", 0x14);
	AddSource("flagName", 0x24);
	AddBool("checkIsSet", 0x30);
	AddBool("checkOnMainAvatar", 0x31);
}