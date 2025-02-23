#include "Header.h"
#include "Manipulation\API.h"
#include "Manipulation\Bypass.h"
#include "Manipulation\MainWorker.h"
#include "Tools\Exceptions.h"

//DWORD AOgame = (DWORD)GetModuleHandle("AOgame.exe");
BreakPoints BP;

void InitHook()
{
	Mhook_SetHook(&(PVOID&)Window, NewWindow);
	Mhook_SetHook(&(PVOID&)CrFileA, NewCrFileA);
}

void InitBreaks()
{
	BypassFileCheck();
	HackingXDB();
}

void Initialization()
{
	InitHook();
	InitBreaks();
}

BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		ShowConsole();
		EnableExceptions();
		StartRoutine(Initialization);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TerminateProcess(GetCurrentProcess(), 0x0);
	}
	return TRUE;
}
