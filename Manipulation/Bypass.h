#pragma once
#include "../Header.h"
#include "../Tools/PatternSearch.h"

DWORD FAddr = 0;
DWORD FOff = 0;
void __declspec(naked) FileHack(void) {
        __asm {
                jmp[FOff]
        }
}

void BypassFileCheck()
{
        if (!FAddr)
        {
                // Example pattern for the file check routine. Replace with the actual bytes for your build.
                static const std::vector<int> pattern = { 0x55, 0x8B, 0xEC }; // TODO: update pattern
                FAddr = static_cast<DWORD>(FindPattern(L"AOgame.exe", pattern));
                if (FAddr)
                        FOff = FAddr + 0x42; // TODO: update offset
        }
        if (FAddr && FOff)
                BP.AddAddr(FAddr, &FileHack, 3);
}