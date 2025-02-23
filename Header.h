//***********************************************************************//
//-----------------------<Project by Bruno3000>--------------------------//
//.........................SOFT_ALLODS_ONLINE............................//
//......................///VERSION = 7.0.1.25///.........................//
//............................<<PACK_BIN>>...............................//
//.........................<<DESTRUCTURIZATOR>>..........................//
//...............................<<TO>>..................................//
//.............................<<$X_D_B$>>...............................//
//***********************************************************************//
//**************************START: 10.04.2016****************************//
//***********************************************************************//
#pragma once

using namespace std;
//=====================DEFINES======================//
#define StartRoutine(Function) CreateThread(0,0,(LPTHREAD_START_ROUTINE)Function,0,0,0);
#define XDocument tinyxml2::XMLDocument
#define XElement tinyxml2::XMLElement *
//-----------------------ALT------------------------//
#define PAUSE 0
#define UNPACK_MODE 0
#define UNPACK_LIST 1
#define LIST_NAME "AO.txt"
//=====================DEFINES======================//

//=====================INCLUDES======================//
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <psapi.h>
#include "../../AllodsNew/tinyxml2/tinyxml2.h"
#include "Tools/BreakPoints.h"
#include "Mhook/mhook-lib/mhook.h"
#include "Containers/Containers.h"
#include "Containers/Unpacker.h"
#include "Enums/Enums.h"
#include "Tools/VFS.h"
//=====================INCLUDES======================//

//=====================LIBS======================//
#pragma comment(lib, "psapi.lib")
#pragma comment(lib, "tinyxml2.lib")
//#pragma comment(lib, "nana_v140_Release_x86.lib")
//=====================LIBS======================//

//=====================VARS======================//
//extern DWORD AOgame;
extern BreakPoints BP;
//extern VFS vfs;
//=====================VARS======================//

//=====================MAIN_FUNCTIONS======================//
void ShowConsole();
BOOL CrDir(LPCTSTR sPathTo);
void WriteBytes(void *adr, void *ptr, int size);
//=====================MAIN_FUNCTIONS======================//