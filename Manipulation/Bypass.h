#pragma once
#include "../Header.h"

DWORD FAddr = 0x0182BE37;
DWORD FOff = 0x0182BE79;
void __declspec(naked) FileHack(void) {
	__asm {
		jmp[FOff]
	}
}

void BypassFileCheck()
{
	BP.AddAddr(FAddr, &FileHack, 3);
}