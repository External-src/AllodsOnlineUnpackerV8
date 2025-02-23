#pragma once
#include "../../Header.h"
class WeatherCreatureVisAction : public Module
{
public:
	WeatherCreatureVisAction(DWORD struct_addr, string name, XDocument * d);
	~WeatherCreatureVisAction();

	void Init();
};