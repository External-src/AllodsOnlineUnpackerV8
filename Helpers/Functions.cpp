#include "../Header.h"

void ShowConsole()
{
	if (AllocConsole()) {
		freopen("CONOUT$", "w", stdout);
		SetConsoleTitleA("Console");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf("Dll Succefull Attached!\n");
		printf("ProjectX -<DESTRUCTURIZATOR>-\n");
		printf("Wait...\n");
	}
}

BOOL CrDir(LPCTSTR sPathTo)
{
	BOOL bRet = sPathTo ? TRUE : FALSE;
	//пока директори€ не создана, будем пытатьс€ еЄ создать
	while (bRet && (bRet = CreateDirectory(sPathTo, NULL)) == FALSE)
	{
		// директори€ не создана, поэтому нужно сначала создать ФпредыдущуюФ директорию
		__try {
			int k = lstrlen(sPathTo);
			if (k >= MAX_PATH) break; // —лишком длинное им€....
			LPTSTR   sTemp = LPTSTR(_alloca((k + 1) * sizeof(TCHAR))); // Ёкономи€ стека :)
			lstrcpy(sTemp, sPathTo);
			while (k && sTemp[k] != TCHAR('\\') && sTemp[k] != TCHAR('/')) --k;
			if (k <= 0) break; // похоже, что директори€ создана быть вообще не может! 
			sTemp[k] = TCHAR('\0');
			bRet = CrDir(sTemp);
		}
		__except (GetExceptionCode() == STATUS_STACK_OVERFLOW) { break; }
	}
	return bRet;
}

void WriteBytes(void *adr, void *ptr, int size)
{
	DWORD OldProtection;
	VirtualProtect(adr, size, PAGE_EXECUTE_READWRITE, &OldProtection);
	memcpy(adr, ptr, size);
	VirtualProtect(adr, size, OldProtection, &OldProtection);
}

//=====================EXPORT======================//
extern "C" __declspec(dllexport) char * __stdcall Inject_My_From_Allods_Online()
{
	return "Thank you, very much!";
}
//=====================EXPORT======================//