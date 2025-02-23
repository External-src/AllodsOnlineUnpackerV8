#include "VisEffectBaseList.h"

VisEffectBaseList::VisEffectBaseList(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

VisEffectBaseList::~VisEffectBaseList()
{
}

void VisEffectBaseList::Init()
{
	FORCON("effects", 0x18, 0x40)
	{
		m->AddInt("delay", 0x4);
		m->AddHref("effectAlias", 0x8);
		OPENEX_X("effectAnimations", 0x10)
		{
			FORNOTX("animations", 0x4, 0x4)
			{
				m->AddText("Item", Enums::GetAnimation(m->Read(i)));
			}
			m->AddText("mode", Enums::GetAnimMode(m->Read(0x14)));
		}
		m->AddHref("effectFx", 0x28);
		m->AddInt("fadeInTime", 0x30);
		m->AddInt("fadeOutTime", 0x34);
		m->AddFloat("scale", 0x38);
		m->AddBool("fixPoint", 0x3C);
		m->AddBool("lockScale", 0x3D);
		m->AddBool("muteFxSounds", 0x3E);
	}
}