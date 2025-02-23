#pragma once
#include "../Containers/Containers.h"
#include "../Header.h"
#include "../Unpack/Module.h"

class Unpacker
{
private:
	TCHAR NPath[MAX_PATH];
	char * out_dir;
	void InitConstructors();

public:
	void UnpackList(string flist);
	void UnpackFiles();
	void UnpackEmptyFiles();
	Unpacker(char * dir = "Extracted");
	~Unpacker();
};

