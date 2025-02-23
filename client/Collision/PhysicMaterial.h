#pragma once
#include "../../Header.h"
class PhysicMaterial : public Module
{
public:
	PhysicMaterial(Item item);
	~PhysicMaterial();

	void Init();
};