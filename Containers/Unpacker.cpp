#include "Unpacker.h"

ofstream logger;
vector<string> ignoreList;

bool StrCmp(string str1, string str2)
{
	for (int i = 0; str1[i] && str2[i]; i++)
	{
		if (str1[i] == '*' || str2[i] == '*')
			return true;
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}

bool CheckIgnore(string xdb)
{
	for (int i = 0; i < ignoreList.size(); i++)
	{
		if (StrCmp(xdb, ignoreList[i]))
			return true;
	}
	return false;
}

void LoadIgnoreList(string fname = "AOIgnore.txt")
{
	string s;
	ifstream file(fname);
	while (getline(file, s))
	{
		if (s.length() != 0)
			ignoreList.push_back(s);
	}
	file.close();
}

Unpacker::Unpacker(char * dir)
{
	GetCurrentDirectory(MAX_PATH, NPath);
	out_dir = dir;
	CrDir(dir);
	InitConstructors();
	LoadIgnoreList();
	logger.open("log.txt");
}

Unpacker::~Unpacker()
{
	logger.close();
}

long s = 0;
long Count = 0;
void Print()
{
	do
	{
		system("cls");
		cout << "==============================" << endl;
		cout << "Unpacked: " << s << "/" << Count << endl;
		cout << "==============================" << endl;
		Sleep(100);
	} while (s < Count);
	s = 0;
}

HANDLE hThread;
void Unpacker::UnpackList(string flist)
{

	system("cls");
	cout << "==============================" << endl;
	cout << "Unpack List started" << endl;
	cout << "==============================" << endl;

	vector<int> ids;
	string sd;
	ifstream file(flist);
	while (getline(file, sd))
	{
		for (int i = 0; i < items.size(); i++)
		{
			string f = items[i].xdb;
			if (StrCmp(f, sd) && !CheckIgnore(f) && Module().CheckXDB(items[i]))
			{
				ids.push_back(i);
			}
		}
	}
	file.close();
	
	Count = ids.size();

	hThread = StartRoutine(Print);
	//ofstream f("log.txt");
	for (int i = 0; i < ids.size(); i++)
	{
		logger << items[ids[i]].xdb << endl;
		SetCurrentDirectory(NPath);
		//f << items[ids[i]].xdb << endl;
		Module * mod = Module().GetXDB(items[ids[i]]);
		SetCurrentDirectory(out_dir);
		if (mod != NULL)
		{
			mod->SaveXDB();
			s++;
			delete mod;
		}
	}
	//f.close();
	WaitForSingleObject(hThread, INFINITE);

	SetCurrentDirectory(NPath);
	system("cls");
	cout << "==============================" << endl;
	cout << "Unpack finished" << endl;
	cout << "==============================" << endl;
	system("pause");
}

void Unpacker::UnpackFiles()
{
	//ofstream f("gameMechanics.log");
	//for (int i = 0; i < constructors.size(); i++)
	//{
	//	f << "====================================" << endl;
	//	f << constructors[i].struct_name << " = " << hex << constructors[i].Address << endl;
	//}
	//exit(0x0);
	system("pause");
	system("cls");
	cout << "==============================" << endl;
	cout << "Unpack started" << endl;
	cout << "==============================" << endl;

	int size = items.size();
	for (int i = 0; i < size; i++)
	{
		Module(items[i], &Count);
	}

	HANDLE hThread = StartRoutine(Print);

	for (int i = 0; i < items.size(); i++)
	{
		SetCurrentDirectory(NPath);
		Module * mod = Module().GetXDB(items[i]);
		SetCurrentDirectory(out_dir);
		if (mod != NULL)
		{
			mod->SaveXDB();
			s++;
			delete mod;
		}	
	}
	SetCurrentDirectory(NPath);
//	WaitForSingleObject(hThread, INFINITE);
	system("cls");
	cout << "==============================" << endl;
	cout << "Unpack finished" << endl;
	cout << "==============================" << endl;
	system("pause");
}

void Unpacker::UnpackEmptyFiles()
{
	system("cls");
	cout << "==============================" << endl;
	cout << "Empty-Unpack started" << endl;
	cout << "==============================" << endl;

	int size = items.size();
	Count = size;

	StartRoutine(Print);
	for (int i = 0; i < size; i++)
	{
		tinyxml2::XMLDocument doc;
		doc.InsertEndChild(doc.NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\" "));
		XElement root = doc.NewElement(items[i].constructor_name);
		doc.InsertEndChild(root);
		doc.SaveFile(items[i].xdb);
		s++;
	}

	system("cls");
	cout << "==============================" << endl;
	cout << "Empty-Unpack finished" << endl;
	cout << "==============================" << endl;
	system("pause");
}

void Unpacker::InitConstructors()
{
	system("cls");
	cout << "==============================" << endl;
	cout << "Start Constructor Initializator" << endl;
	cout << "==============================" << endl;

	long size = items.size();
	long size_c = constructors.size();

	for (int i = 0; i < size; i++)
	{
		if (items[i].struct_addr != NULL && items[i].xdb != NULL)
		{
			for (int j = 0; j < size_c; j++)
			{
				if (*(DWORD*)(items[i].struct_addr) == constructors[j].Address)
				{
					items[i].constructor_name = constructors[j].struct_name;
					break;
				}
			}
		}
	}

	system("cls");
	cout << "==============================" << endl;
	cout << "Finished Constructor Initializator" << endl;
	cout << "==============================" << endl;
}