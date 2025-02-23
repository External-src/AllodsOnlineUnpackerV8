#pragma once
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>

using namespace nana;

class MainDlg : public form
{
public:
	MainDlg();
	~MainDlg();

private:
	button UnpackButton;
};

