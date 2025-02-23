#include "CreatureStepSoundParamAction.h"

CreatureStepSoundParamAction::CreatureStepSoundParamAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.CreatureStepSoundParamAction");
	Init();
}

CreatureStepSoundParamAction::~CreatureStepSoundParamAction()
{
}

void CreatureStepSoundParamAction::Init()
{
	AddSource("visActionID", 0x14);
	OPENEX("param", 0x24)
	{
		m->AddHref("parameter", 0x4);
		m->AddFloat("value", 0x0C);
	}
	AddBool("onlyIfOnMainAvatar", 0x34);
}