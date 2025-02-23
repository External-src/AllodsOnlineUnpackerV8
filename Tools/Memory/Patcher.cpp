#include "Patcher.h"


Patcher::Patcher()
{
}


Patcher::~Patcher()
{
}

BOOL Patcher::PlaceJMP(LPVOID pSrc, void *pDest, int nNops)
{	
	DWORD OldProt;
	if (!VirtualProtect(pSrc, 5 + nNops, PAGE_EXECUTE_READWRITE, &OldProt)) 
		return false;
	ABSD a;
	a.addr = pSrc;
	a.ori = new BYTE[5 + nNops];
	memcpy(a.ori, pSrc, 5 + nNops);
	a.Size = 5 + nNops;
	addrs.push_back(a);

	*(char*)pSrc = (char)0xE9;
	*(DWORD*)((DWORD)pSrc + 1) = (DWORD)pDest - (DWORD)pSrc - 5;

	for (int i = 0; i < nNops; ++i) 
	{ *(BYTE*)((DWORD)pSrc + 5 + i) = 0x90; }

	if(!VirtualProtect(pSrc, 5 + nNops, OldProt, &OldProt)) 
		return false;
	return true;
}

BOOL Patcher::ClearJMP(LPVOID pSrc)
{
	int i;
	for (i = 0; i < addrs.capacity() && addrs[i].addr != pSrc; i++)
		;
	if (i == addrs.capacity()) return false;

	DWORD OldProt;
	if (!VirtualProtect(pSrc, addrs[i].Size, PAGE_EXECUTE_READWRITE, &OldProt))
		return false;
	memcpy(addrs[i].addr, addrs[i].ori, addrs[i].Size);
	if (!VirtualProtect(pSrc, addrs[i].Size, OldProt, &OldProt)) 
		return false;
	addrs.erase(addrs.begin() + i);
	return true;
}

BYTE * Patcher::GetOriBytes(LPVOID pSrc)
{
	int i;
	for (i = 0; i < addrs.capacity() && addrs[i].addr != pSrc; i++)
		;
	if (i == addrs.capacity()) return NULL;

	return addrs[i].ori;
}