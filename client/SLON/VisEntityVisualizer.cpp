#include "VisEntityVisualizer.h"

VisEntityVisualizer::VisEntityVisualizer(DWORD struct_addr, string name, XDocument * d)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	main = struct_addr;
	AddAttribute("type", "client.SLON.VisEntityVisualizer");
	Init();
}

VisEntityVisualizer::~VisEntityVisualizer()
{
}

void VisEntityVisualizer::Init()
{
	AddHref("collision", 0x18);
	FORCON("matches", 0x20, 0x1C)
	{
		m->AddHref("collision", 0x4);
		m->AddHref("parentVisObj", 0x0C);
		m->AddHref("visObj", 0x14);
	}
	AddFloat("scale", 0x30);
	AddHref("visObj", 0x34);
	AddBool("collisionObject", 0x3C);
	AddBool("interactiveObject", 0x3D);
	AddBool("matchShipSkin", 0x3E);
	AddBool("useDelayedCollision", 0x3F);
}