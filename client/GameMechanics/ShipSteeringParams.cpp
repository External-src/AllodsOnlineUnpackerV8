#include "ShipSteeringParams.h"

ShipSteeringParams::ShipSteeringParams(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

ShipSteeringParams::~ShipSteeringParams()
{
}

void ShipSteeringParams::Init()
{
	AddFloat("agility", 0x18);
	AddFloat("maxPitch", 0x1C);
	AddFloat("maxRoll", 0x20);
	AddFloat("pitchMul", 0x24);
	AddFloat("rollMul", 0x28);
	AddFloat("shakeAmplitude", 0x2C);
	AddFloat("shakePeriod", 0x30);
}