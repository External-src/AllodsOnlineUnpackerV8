#pragma once
#include "../Header.h"
#include "../Containers/Containers.h"
#include "../Tools/PatternSearch.h"

//==================Items_Initialization==================//
void Fill_Items_Container(PCONTEXT db)
{
	Item n;
	n.struct_addr = db->Ebx + db->Edx * 4 - 0x0C;
	n.xdb = (char*)db->Edi;
	items.push_back(n);
}

DWORD ItemsInitAddr = 0;
DWORD ItemsInitOff = 0;

void __declspec(naked) ItemsInit(void) {
	__asm {
		mov[ebx + edx * 4], edi
			jmp[ItemsInitOff]
	}
}
//==================Items_Initialization==================//

//==================Construction_Init==================//
void Fill_Constructors_NotXDB_Container(PCONTEXT db)
{
	Construct_Container c;
	c.struct_name = (char*)(*(DWORD*)(db->Esp + 0x8));
	c.Address = db->Ecx;//*(DWORD*)(db->Esp + 0x60);
	constructors.push_back(c);
}
const DWORD ConstructorInitNotAddr_A = 0x0043BAE1;
const DWORD ConstructorInitNotOff_A = 0x0043BAE3;

void __declspec(naked) ConstructionInitNot(void) {
	__asm {
		mov ebp, esp
			jmp[ConstructorInitNotOff_A]
	}
}
//==================Construction_Init==================//
ofstream log_con("containers.txt");
void Fill_Constructors_Container(PCONTEXT db)
{
	Construct_Container c;
	c.struct_name = (char*)(*(DWORD*)(db->Esp + 0x8));
	c.Address = *(DWORD*)(db->Esp + 0x28);
	constructors.push_back(c);
	log_con << hex << c.Address << " = " << string(c.struct_name) << endl;
}

DWORD ConstructorInitAddr = 0;
DWORD ConstructorInitOff = 0;

void __declspec(naked) ConstructionInit(void) {
	__asm {
		mov ebp, esp
			jmp[ConstructorInitOff]
	}
}
//==================Construction_Init==================//

void HackingXDB()
{
        if (!ItemsInitAddr)
        {
                static const std::vector<int> itemsPattern = { 0x89, 0x3C, 0x8B }; // TODO: update pattern
                ItemsInitAddr = static_cast<DWORD>(FindPattern(L"AOgame.exe", itemsPattern));
                if (ItemsInitAddr)
                        ItemsInitOff = ItemsInitAddr + 0x03; // TODO: update offset
        }
        if (!ConstructorInitAddr)
        {
                static const std::vector<int> ctorPattern = { 0x8B, 0xC8, 0x89 }; // TODO: update pattern
                ConstructorInitAddr = static_cast<DWORD>(FindPattern(L"AOgame.exe", ctorPattern));
                if (ConstructorInitAddr)
                        ConstructorInitOff = ConstructorInitAddr + 0x02; // TODO: update offset
        }
        if (ItemsInitAddr && ItemsInitOff)
                BP.AddAddr(ItemsInitAddr, &ItemsInit, 1, Fill_Items_Container);
        if (ConstructorInitAddr && ConstructorInitOff)
                BP.AddAddr(ConstructorInitAddr, &ConstructionInit, 2, Fill_Constructors_Container);
}