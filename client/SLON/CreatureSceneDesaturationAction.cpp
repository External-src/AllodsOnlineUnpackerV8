#include "CreatureSceneDesaturationAction.h"

CreatureSceneDesaturationAction::CreatureSceneDesaturationAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureSceneDesaturationAction");
	Init();
}

CreatureSceneDesaturationAction::~CreatureSceneDesaturationAction()
{
}

void CreatureSceneDesaturationAction::Init()
{
	AddSource("visActionID", 0x14);
	AddFloat("desaturationForce", 0x24);
	AddBool("onlyIfOnMainAvatar", 0x28);
}