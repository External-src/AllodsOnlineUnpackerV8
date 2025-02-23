#pragma once
#include "../../Header.h"
class AnimationController : public Module
{
public:
	AnimationController(Item item);
	~AnimationController();

	void Init();
};