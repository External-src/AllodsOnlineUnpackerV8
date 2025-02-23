#pragma once
#include <Windows.h>
#include <vector>

using namespace std;

typedef struct Construct_Container 
{
	char * struct_name;
	DWORD Address;

} Construct_Container;

typedef struct Item 
{
	DWORD struct_addr;
	char* xdb;
	char* constructor_name;

} Item;

extern vector<Item> items;
extern vector<Construct_Container> constructors;