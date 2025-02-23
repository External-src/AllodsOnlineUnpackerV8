#pragma once
#include "../Header.h"
#include "../Containers/Containers.h"

//==================Items_Initialization==================//
void Fill_Items_Container(PCONTEXT db)
{
	Item n;
	n.struct_addr = db->Ebx + db->Edx * 4 - 0x0C;
	n.xdb = (char*)db->Edi;
	items.push_back(n);
}

const DWORD ItemsInitAddr = 0x00D41299;
const DWORD ItemsInitOff = 0x00D4129C;

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

const DWORD ConstructorInitAddr = 0x00586B11;
const DWORD ConstructorInitOff = 0x00586B13;

void __declspec(naked) ConstructionInit(void) {
	__asm {
		mov ebp, esp
			jmp[ConstructorInitOff]
	}
}
//==================Construction_Init==================//

void HackingXDB()
{
	BP.AddAddr(ItemsInitAddr, &ItemsInit, 1, Fill_Items_Container);
	BP.AddAddr(ConstructorInitAddr, &ConstructionInit, 2, Fill_Constructors_Container);
}