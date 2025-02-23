#pragma once
#include "../../Header.h"
class WeatherType : public Module
{
public:
	WeatherType(Item item);
	~WeatherType();

	void Init();
};