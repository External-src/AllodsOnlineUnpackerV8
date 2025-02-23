#pragma once
#include "../Header.h"
class StaticObject : public Module
{
public:
	StaticObject(Item item);
	~StaticObject();

	void Init();
};