#pragma once
#include "../../../../Header.h"
class Spell : public Module
{
public:
	Spell(Item item);
	~Spell();

	void Init();
};