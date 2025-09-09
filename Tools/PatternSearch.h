#pragma once
#include <vector>
#include <cstdint>
#include <windows.h>
#include <psapi.h>

// Searches a module's memory for a given byte pattern.
// Use -1 as a wildcard byte in the pattern.
inline uintptr_t FindPattern(const wchar_t* module, const std::vector<int>& pattern)
{
    HMODULE hMod = GetModuleHandleW(module);
    if (!hMod)
        return 0;

    MODULEINFO mi{};
    if (!GetModuleInformation(GetCurrentProcess(), hMod, &mi, sizeof(mi)))
        return 0;

    auto* base = static_cast<unsigned char*>(mi.lpBaseOfDll);
    size_t size = mi.SizeOfImage;
    size_t patternSize = pattern.size();

    if (patternSize == 0 || size < patternSize)
        return 0;

    for (size_t i = 0; i <= size - patternSize; ++i) {
        bool found = true;
        for (size_t j = 0; j < patternSize; ++j) {
            int byte = pattern[j];
            if (byte != -1 && base[i + j] != static_cast<unsigned char>(byte)) {
                found = false;
                break;
            }
        }
        if (found) {
            return reinterpret_cast<uintptr_t>(base + i);
        }
    }
    return 0;
}
