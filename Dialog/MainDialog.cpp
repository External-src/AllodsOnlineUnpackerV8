#include "MainDialog.h"

MainDialog::MainDialog(HINSTANCE hInstance, LPCSTR dlgResName, HWND hwndParent) : DlgBoxTemplate(hInstance, dlgResName, hwndParent)
{
	OnCreate();
}


MainDialog::~MainDialog()
{
}

void MainDialog::OnCreate()
{
	
}

LRESULT MainDialog::RealDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{

	}
	return DlgBoxTemplate::RealDlgProc(hwnd, uMsg, wParam, lParam);
}