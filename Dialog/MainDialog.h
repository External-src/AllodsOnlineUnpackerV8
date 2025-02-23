#pragma once
#include "DlgBoxTemplate.h"

class MainDialog :
	public DlgBoxTemplate
{
public:
	void OnCreate();
	LRESULT RealDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	MainDialog(HINSTANCE hInstance, LPCSTR dlgResName, HWND hwndParent);
	~MainDialog();
};

