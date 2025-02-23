#include "WeatherType.h"

WeatherType::WeatherType(Item item)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version =\"1.0\" encoding=\"UTF-8\" ")); 
	root = doc->NewElement(item.constructor_name);
	doc->InsertEndChild(root);
	main = item.struct_addr;
	Init();
}

WeatherType::~WeatherType()
{
}

void WeatherType::Init()
{
}