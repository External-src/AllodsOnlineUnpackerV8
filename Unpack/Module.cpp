#include "Module.h"
#include "../client/client.h"
//#include "../Tools/LogMod.h"

#pragma region LOGGER
ofstream fout("errorV8.log");
#define FILTER GetExceptionCode(), GetExceptionInformation()

int filter(DWORD addr, string text, unsigned int code, _EXCEPTION_POINTERS * ep)
{
	fout << "====================================" << endl;
	fout << text << endl;
	if (code == EXCEPTION_ACCESS_VIOLATION) {
		fout << "EXCEPT ADDRESS: " << std::hex << addr << endl;
		fout << "ACCESS VIOLATION" << endl;
		return EXCEPTION_EXECUTE_HANDLER;
	}
	else {
		fout << "didn't catch AV, unexpected." << endl;
		return EXCEPTION_CONTINUE_SEARCH;
	};
}
#pragma endregion

Module::Module()
{
}

Module::Module(string name, DWORD offset, XDocument * d, XElement elem)
{
	doc = d;
	root = doc->NewElement(name.c_str());
	elem->InsertEndChild(root);
	main = offset;
}

Module::Module(DWORD struct_addr, string mod_name)
{
	doc = new XDocument;
	doc->InsertEndChild(doc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\" "));
	root = doc->NewElement(mod_name.c_str());
	doc->InsertEndChild(root);
	main = struct_addr;
}

Module::Module(DWORD struct_addr, string mod_name, XDocument * d, XElement elem)
{
	doc = d;
	root = doc->NewElement(mod_name.c_str());
	elem->InsertEndChild(root);
	main = struct_addr;
}

DWORD Module::GetForSize(DWORD offset)
{
	DWORD start = Read(offset);
	DWORD end = Read(offset + 0x4);
	DWORD size = end - start;
	return size;
}

string Module::GetConstructor(DWORD offset)
{
	if (*(DWORD*)(main + offset) == NULL) return "";
	DWORD addr = main + offset;
	DWORD pCon = *(DWORD*)(addr + 0x0C);
	if (pCon == NULL) return "";
	char * con = (char*)*(DWORD*)(pCon + 0x10);
	return con;
}

string Module::GetConstructorFromAddr(DWORD Addr)
{
	if (*(DWORD*)(Addr) == NULL) return "";
	DWORD pCon = *(DWORD*)(Addr + 0x0C);
	if (pCon == NULL) return "";
	char * con = (char*)*(DWORD*)(pCon + 0x10);
	return con;
}

void Module::SaveXDB()
{
	if (root == NULL) return;

	char * pXdb = (char*)*(DWORD*)(main + 0x0C);
	string xdb = pXdb;
	string Dir = xdb.substr(0, xdb.rfind("/") + 1);
	CrDir(Dir.c_str());
	doc->SaveFile(xdb.c_str());
}

Module::~Module()
{
	if (doc != NULL)
	{
		doc->Clear();
		delete doc;
	}
}

XElement Module::GetRoot()
{
	return root;
}

XDocument * Module::GetDocument()
{
	return doc;
}

string Module::GetPatch()
{
	char * pXdb = (char*)*(DWORD*)(main + 0x0C);
	string xdb = pXdb;
	return xdb;
}

DWORD Module::GetMain()
{
	return main;
}

XElement Module::Href(string name, string href)
{
	XElement elem = doc->NewElement(name.c_str());
	elem->SetAttribute("href", href.c_str());
	return elem;
}

XElement Module::Type(string name, string type)
{
	XElement el = doc->NewElement(name.c_str());
	el->SetAttribute("type", type.c_str());
	return el;
}

XElement Module::Value(string name, string value)
{
	XElement el = doc->NewElement(name.c_str());
	el->SetText(value.c_str());
	return el;
}


string Module::GetHref(DWORD offset)
{
	DWORD pCont = *(DWORD*)(main + offset);
	if (pCont == NULL)
		return nullptr;

	string str = "/" + string((char*)(*(DWORD*)(pCont + 0x0C)));
	for (int i = 0; i < constructors.size(); i++)
	{
		if (*(DWORD*)pCont == constructors[i].Address)
		{
			str += "#xpointer(/" + string(constructors[i].struct_name) + ")";
			break;
		}
	}
	return str;
}

string Module::GetBool(DWORD offset)
{
	bool b = *(bool*)(main + offset);
	return b ? "true" : "false";
}

string Module::GetFloat(DWORD offset)
{
	float b = *(float*)(main + offset);
	stringstream ss;
	ss << b;
	return ss.str();
}

string Module::GetInt(DWORD offset)
{
	int b = *(int*)(main + offset);
	return to_string(b);
}

string Module::GetLong(DWORD offset)
{
	long b = *(long*)(main + offset);
	return to_string(b);
}

string Module::GetTxt(DWORD offset)
{
	char * txt = (char*)*(DWORD*)(main + offset);
	string str = "/" + string(txt);
	return str;
}

string Module::GetText(DWORD offset)
{
	char * txt = (char*)*(DWORD*)(main + offset);
	return txt;
}

void Module::AddHref(string name, DWORD offset)
{
	if (*(DWORD*)(main + offset) == NULL) return;

	if (IsBadReadPtr((LPVOID)*(DWORD*)(main + offset), 4))
	{
		fout << "=====================" << endl;
		fout << "Error AddHref" << endl;
		fout << "BAD POINTER: " << std::hex << *(DWORD*)(main + offset) << endl;
		fout << "EXCEPT ADDRESS: " << std::hex << main + offset << endl;
		fout << "OFFSET: +" << std::hex << offset << endl;
		return;
	}

	root->InsertEndChild(Href(name, GetHref(offset)));
}

void Module::AddHrefSource(string name, DWORD offset)
{
	if (*(DWORD*)(main + offset) != NULL)
		root->InsertEndChild(Href(name, GetText(offset)));
}

void Module::AddBool(string name, DWORD offset)
{
	//if (*(bool*)(main + offset) != false)
		root->InsertEndChild(Value(name, GetBool(offset)));
}

void Module::AddInt(string name, DWORD offset)
{
	//if (*(int*)(main + offset) != NULL)
		root->InsertEndChild(Value(name, GetInt(offset)));
}

void Module::AddLong(string name, DWORD offset)
{
	//if (*(long*)(main + offset) != NULL)
		root->InsertEndChild(Value(name, GetInt(offset)));
}

void Module::AddFloat(string name, DWORD offset)
{
	if (*(float*)(main + offset) != NULL && *(float*)(main + offset) != -1)
		root->InsertEndChild(Value(name, GetFloat(offset)));
}

void Module::AddTxt(string name, DWORD offset)
{
	if (*(DWORD*)(main + offset) == NULL) return;

	if (IsBadReadPtr((LPVOID)*(DWORD*)(main + offset), 4))
	{
		fout << "=====================" << endl;
		fout << "Error AddTxt" << endl;
		fout << "BAD POINTER: " << std::hex << *(DWORD*)(main + offset) << endl;
		fout << "EXCEPT ADDRESS: " << std::hex << main + offset << endl;
		fout << "OFFSET: +" << std::hex << offset << endl;
		return;
	}

	root->InsertEndChild(Href(name, GetTxt(offset)));
}

void Module::AddSource(string name, DWORD offset)
{
	if (*(DWORD*)(main + offset) == NULL) return;

	if (IsBadReadPtr((LPVOID)*(DWORD*)(main + offset), 4))
	{
		fout << "=====================" << endl;
		fout << "Error AddSource" << endl;
		fout << "BAD POINTER: " << std::hex << *(DWORD*)(main + offset) << endl;
		fout << "EXCEPT ADDRESS: " << std::hex << main + offset << endl;
		fout << "OFFSET: +" << std::hex << offset << endl;
		return;
	}

	root->InsertEndChild(Value(name, GetText(offset)));
}

void Module::AddText(string name, string text)
{
	root->InsertEndChild(Value(name, text));
}

void Module::AddContainer(XElement container)
{
	root->InsertEndChild(container);
}

void Module::AddBinFile(string name, DWORD offset)
{
	if (*(DWORD*)(main + offset) != NULL)
	{
		if (IsBadReadPtr((LPVOID)*(DWORD*)(main + offset), 4))
		{
			fout << "=====================" << endl;
			fout << "Error AddBinFile" << endl;
			fout << "BAD POINTER: " << std::hex << *(DWORD*)(main + offset) << endl;
			fout << "EXCEPT ADDRESS: " << std::hex << main + offset << endl;
			fout << "OFFSET: +" << std::hex << offset << endl;
			return;
		}
		root->InsertEndChild(Href(name, GetText(offset)));
		return;
	}
	DWORD binAddr = main + offset;
	DWORD archive = *(DWORD*)(binAddr + 0x0C);
	DWORD arc_offset = *(DWORD*)(binAddr + 0x10);
	if (archive <= 0x0 || arc_offset < 0)
		return;
	DWORD newAddr = *(DWORD*)(archive + 0x14);
	DWORD ptrUnarc = newAddr + arc_offset * 4;
	DWORD unarc = *(DWORD*)(ptrUnarc);

	DWORD size = *(DWORD*)(unarc + 0x1C);
	char * bin = (char*)unarc + 0x2E;

	string newBin = "/" + string(bin);
	newBin.resize(size + 1);
	root->InsertEndChild(Href(name, newBin));
}

void Module::AddVector2(string name, DWORD offset)
{
	if (Module * m = OpenEx(name, offset))
	{
		m->AddAttribute("x", m->GetFloat(0x0));
		m->AddAttribute("y", m->GetFloat(0x4));
	}
}

void Module::AddVector3(string name, DWORD offset)
{
	if (Module * m = OpenEx(name, offset))
	{
		m->AddAttribute("x", m->GetFloat(0x0));
		m->AddAttribute("y", m->GetFloat(0x4));
		m->AddAttribute("z", m->GetFloat(0x8));
	}
}

void Module::AddRotation3(string name, DWORD offset)
{
	if (Module * m = OpenEx(name, offset))
	{
		m->AddAttribute("x", m->GetFloat(0x0));
		m->AddAttribute("y", m->GetFloat(0x4));
		m->AddAttribute("z", m->GetFloat(0x8));
		m->AddAttribute("w", m->GetFloat(0x0C));
	}
}

void Module::AddSFX(string name, DWORD offset)
{
	if (Module * m = OpenEx(name, offset))
	{
		m->AddFloat("creationRadius", 0x4);
		m->AddSource("name", 0x8);
		m->AddHref("project", 0x14);
	}
}

void Module::AddSFX2(string name, DWORD offset)
{
	if (Module * m = OpenEx(name, offset))
	{
		m->AddSource("name", 0x4);
		m->AddHref("project", 0x10);
	}
}

void Module::AddAABB(string name, DWORD offset)
{
	if (Module * m = OpenEx(name, offset))
	{
		m->AddVector3("center", 0x0);
		m->AddVector3("extents", 0x0C);
	}
}

//void Module::AddBinSize(string xdb)
//{
//	if (!vfs.FileExists(xdb)) return;
//	root->InsertEndChild(Value("binaryFileSize", to_string(vfs.GetFileSize(xdb))));
//}

void Module::AddAttribute(string attribute, string value)
{
	root->SetAttribute(attribute.c_str(), value.c_str());
}

Module * Module::OpenIn(string name, DWORD offset)
{
	if (*(DWORD*)(main + offset) == NULL)
		return NULL;

	if (IsBadReadPtr((LPVOID)*(DWORD*)(main + offset), 4))
	{
		fout << "=====================" << endl;
		fout << "Error OpenIn" << endl;
		fout << "BAD POINTER: " << std::hex << *(DWORD*)(main + offset) << endl;
		fout << "EXCEPT ADDRESS: " << std::hex << main + offset << endl;
		fout << "OFFSET: +" << std::hex << offset << endl;
		return NULL;
	}

	Module * mod = new Module(*(DWORD*)(main + offset), name, doc, root);
	root->InsertEndChild(mod->GetRoot());
	return mod;
}

Module * Module::OpenEx(string name, DWORD offset, bool MoveOffset)
{
	Module * mod = NULL;
	if (MoveOffset)
		mod = new Module(name, main + offset, doc, root);
	else
		mod = new Module(name, main, doc, root);
	root->InsertEndChild(mod->GetRoot());
	return mod;
}