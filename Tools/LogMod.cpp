#include "LogMod.h"

LogMod::LogMod(string fname)
{
	fout.open(fname);
}

void LogMod::Print(string text)
{
	fout << text << endl;
}

int LogMod::Filter(DWORD addr, string text, unsigned int code, _EXCEPTION_POINTERS * ep)
{
	fout << "====================================" << endl;
	fout << text << endl;
	if (code == EXCEPTION_ACCESS_VIOLATION) {
		fout << "EXCEPT ADDRESS: " << std::hex << addr << endl;
		fout << "ACCESS VIOLATION" << endl;
		return EXCEPTION_EXECUTE_HANDLER;
	}
	else {
		fout << "didn't catch AV, unexpected." << endl;
		return EXCEPTION_CONTINUE_SEARCH;
	};
}

LogMod::~LogMod()
{
	fout.close();
}
