#include "CreatureEventPlaybackEnded.h"

CreatureEventPlaybackEnded::CreatureEventPlaybackEnded(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.CreatureEventPlaybackEnded");
	Init();
}

CreatureEventPlaybackEnded::~CreatureEventPlaybackEnded()
{
}

void CreatureEventPlaybackEnded::Init()
{
	AddSource("visActionID", 0x14);
}