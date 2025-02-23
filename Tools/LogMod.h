#pragma once
#include "../Header.h"

#define FILTER GetExceptionCode(), GetExceptionInformation()

class LogMod
{
private:
	ofstream fout;

public:
	LogMod(string fname);
	~LogMod();

	void Print(string text);
	int Filter(DWORD addr, string text, unsigned int code, struct _EXCEPTION_POINTERS *ep);
};

