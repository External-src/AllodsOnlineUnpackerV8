#include "AnimationController.h"

AnimationController::AnimationController(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

AnimationController::~AnimationController()
{
}

void AnimationController::Init()
{
	FORCON("SkeletonParts", 0x18, 0x14)
	{
		m->AddSource("rootBone", 0x4);
		m->AddBool("enableFlag", 0x10);
		m->AddBool("rootFlag", 0x11);
	}
	AddBool("animationFeedBack", 0x28);
	AddBool("defaultFlag", 0x29);
	AddBool("useMaterialAnimation", 0x2A);
}