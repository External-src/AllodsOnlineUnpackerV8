#pragma once
#include "../../Header.h"
class WeatherVisObjComponent :
	public Module
{
public:
	WeatherVisObjComponent(DWORD struct_addr, string name, XDocument * d);
	~WeatherVisObjComponent();

	void Init();
};

