#include "ForagingVisualizerComponent.h"

ForagingVisualizerComponent::ForagingVisualizerComponent(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.Replica.ForagingVisualizerComponent");
	Init();
}

ForagingVisualizerComponent::~ForagingVisualizerComponent()
{
}

void ForagingVisualizerComponent::Init()
{
	FORCON("states", 0x18, 0x0C)
	{
		m->AddFloat("probability", 0x4);
		m->OpenCon("script", 0x8);
	}
}