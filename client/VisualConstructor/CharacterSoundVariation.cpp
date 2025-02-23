#include "CharacterSoundVariation.h"

CharacterSoundVariation::CharacterSoundVariation(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

CharacterSoundVariation::~CharacterSoundVariation()
{
}

void CharacterSoundVariation::Init()
{
	FORCON("aliasSounds", 0x18, 0x28)
	{
		m->AddHref("alias", 0x4);
		m->AddSFX("sound", 0x0C);
	}
	FORCON("animationSounds", 0x28, 0x28)
	{
		m->AddText("animation", Enums::GetAnimation(0x4));
		m->AddSFX("sound", 0x8);
		m->AddBool("noRepeatSoundOnAnimationLoop", 0x24);
		m->AddBool("replaceOriginalSound", 0x25);
	}
}