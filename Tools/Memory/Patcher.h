#pragma once
#include <Windows.h>
#include <vector>
using std::vector;

class Patcher
{
	struct ABSD
	{
		LPVOID addr;
		BYTE * ori;
		int Size;
	};
	vector<ABSD> addrs;

public:
	BOOL PlaceJMP(LPVOID pSrc, void *pDest, int nNops = 0);
	BOOL ClearJMP(LPVOID pSrc); 

	BYTE * Patcher::GetOriBytes(LPVOID pSrc); //If address include in struct

	Patcher();
	~Patcher();
};

