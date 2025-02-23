#include "Exceptions.h"

extern HANDLE hThread;

void PrintRecords(PCONTEXT db)
{
	cout << "----------REGISTERS----------" << endl;
	printf("EAX: %X\n", db->Eax);
	printf("EBX: %X\n", db->Ebx);
	printf("ECX: %X\n", db->Ecx);
	printf("EDX: %X\n", db->Edx);
	printf("ESI: %X\n", db->Esi);
	printf("EDI: %X\n", db->Edi);
	printf("EBP: %X\n", db->Ebp);
	printf("ESP: %X\n", db->Esp);
	cout << "-----------------------------" << endl;
}

void PrintContext(EXCEPTION_POINTERS* ep)
{
	if (ep->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION)
	{
		cout << "==========ACCESS_VIOLATION==========" << endl;
		printf("Address: %X\n", (DWORD)ep->ExceptionRecord->ExceptionAddress);
	}
}

LONG WINAPI ExceptionHooker(EXCEPTION_POINTERS* ep)
{
	DWORD addr = (DWORD)ep->ExceptionRecord->ExceptionAddress;

	if (addr >= (DWORD)&IsBadReadPtr && addr <= (DWORD)&IsBadReadPtr + 0xAF)
		return EXCEPTION_CONTINUE_SEARCH;

	if (ep->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION)
	{
		SuspendThread(hThread);
		Sleep(1000);
		system("cls");
		PrintContext(ep);
		PrintRecords(ep->ContextRecord);
		system("Pause");
		exit(0x0);
		return EXCEPTION_CONTINUE_EXECUTION;
	}
	else if (ep->ExceptionRecord->ExceptionCode == EXCEPTION_INT_DIVIDE_BY_ZERO)
	{
		SuspendThread(hThread);
		Sleep(1000);
		system("cls");
		cout << "==========DIVISION_BY_ZERO==========" << endl;
		printf("Address: %X\n", (DWORD)ep->ExceptionRecord->ExceptionAddress);
		PrintRecords(ep->ContextRecord);
		system("Pause");
		exit(0x0);
	}
	return EXCEPTION_CONTINUE_SEARCH;
}

void EnableExceptions()
{
	AddVectoredExceptionHandler(1, ExceptionHooker);
}