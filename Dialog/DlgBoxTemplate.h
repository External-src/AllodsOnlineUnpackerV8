#pragma once
#include <Windows.h>

class DlgBoxTemplate
{
public:
	DlgBoxTemplate(HINSTANCE hInstance, LPCSTR dlgResName, HWND hwndParent);
	virtual ~DlgBoxTemplate();
	void Show(int nCmdShow);

private:
	virtual void OnCreate() = 0;
	void CreateDlg(HINSTANCE hInstance, LPCSTR dlgResName, HWND parent);
	static LRESULT WINAPI StDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

protected:
	HWND m_hWnd;
	virtual LRESULT RealDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

