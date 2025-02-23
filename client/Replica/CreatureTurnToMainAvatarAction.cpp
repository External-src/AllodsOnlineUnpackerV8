#include "CreatureTurnToMainAvatarAction.h"

CreatureTurnToMainAvatarAction::CreatureTurnToMainAvatarAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureTurnToMainAvatarAction");
	Init();
}

CreatureTurnToMainAvatarAction::~CreatureTurnToMainAvatarAction()
{
}

void CreatureTurnToMainAvatarAction::Init()
{
	AddSource("visActionID", 0x14);
}