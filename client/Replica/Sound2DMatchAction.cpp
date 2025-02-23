#include "Sound2DMatchAction.h"

Sound2DMatchAction::Sound2DMatchAction(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.Sound2DMatchAction");
	Init();
}

Sound2DMatchAction::~Sound2DMatchAction()
{
}

void Sound2DMatchAction::Init()
{
	AddSource("visActionID", 0x14);
	AddText("comparisonOperator", Enums::GetComparsionOperator(Read(0x24)));
	AddText("match", Enums::GetMatch(Read(0x28)));
	AddSource("pattern", 0x2C);
	AddInt("playingSoundsCount", 0x38);
	FORCON("sounds", 0x3C, 0x1C)
	{
		OPENEX_X("Item", i)
		{
			m->AddSFX2("sound", 0x4);
		}
	}
	AddBool("onlyForMainAvatar", 0x4C);
}