#include "ChainAnimatorComponent.h"

ChainAnimatorComponent::ChainAnimatorComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Scene.ChainAnimatorComponent");
	Init();
}

ChainAnimatorComponent::~ChainAnimatorComponent()
{
}

void ChainAnimatorComponent::Init()
{
	AddSource("VisualObjectComponentID", 0x14);
	FORCON("chains", 0x24, 0x6C)
	{
		OPENEX_X("constraints", 0x4)
		{
			m->AddFloat("acceleration", 0x4);
			m->AddVector3("maxAngle", 0x8);
			m->AddVector3("maxSpeed", 0x14);
			m->AddVector3("minAngle", 0x20);
			m->AddSource("nodeForObserve", 0x2C);
			m->AddBool("drawContraintsX", 0x38);
			m->AddBool("drawContraintsY", 0x39);
			m->AddBool("getRotationFromOriginNode", 0x3A);
			m->AddBool("useContraints", 0x3B);
		}
		m->AddVector3("gravity", 0x40);
		m->AddFloat("mass", 0x4C);
		FORNOTX("nodes", 0x50, 0x0C)
		{
			m->AddSource("Item", i);
		}
		m->AddFloat("resistance", 0x60);
		m->AddFloat("spring", 0x64);
		m->AddBool("useDefaultGravity", 0x68);
	}
}
