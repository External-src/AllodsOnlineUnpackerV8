#include "DlgBoxTemplate.h"



DlgBoxTemplate::DlgBoxTemplate(HINSTANCE hInstance, LPCSTR dlgResName, HWND hwndParent)
{
	CreateDlg(hInstance, dlgResName, hwndParent);
}


DlgBoxTemplate::~DlgBoxTemplate()
{
}

void DlgBoxTemplate::CreateDlg(HINSTANCE hInstance, LPCSTR dlgResName, HWND parent)
{
	m_hWnd = CreateDialog(hInstance, dlgResName, parent, (DLGPROC)StDlgProc);
	SetWindowLongPtr(m_hWnd, GWLP_USERDATA, (LONG_PTR)this);
}

LRESULT CALLBACK DlgBoxTemplate::StDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	DlgBoxTemplate* pDlgTemplate = NULL;

	pDlgTemplate = (DlgBoxTemplate*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
	if(pDlgTemplate != NULL)
	{
		return pDlgTemplate->RealDlgProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}

LRESULT DlgBoxTemplate::RealDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_INITDIALOG:
		break;
	case WM_CLOSE:
		EndDialog(hwnd, wParam);
		PostQuitMessage(0x0);
		break;
	}
	return 0;
}

void DlgBoxTemplate::Show(int nCmdShow)
{
	ShowWindow(m_hWnd, nCmdShow);
}