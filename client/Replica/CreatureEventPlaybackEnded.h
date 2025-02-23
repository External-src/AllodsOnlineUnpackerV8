#pragma once
#include "../../Header.h"
class CreatureEventPlaybackEnded : public Module
{
public:
	CreatureEventPlaybackEnded(DWORD struct_addr, string name, XDocument * d);
	~CreatureEventPlaybackEnded();

	void Init();
};