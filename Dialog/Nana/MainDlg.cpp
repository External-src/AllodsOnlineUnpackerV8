#include "MainDlg.h"
#include "../../Tools/Unpacker.h"

void Unpack()
{
	Unpacker u("Extracted/");
	u.Init();
	u.InitConstructors();
	u.UnpackFiles();
}

MainDlg::MainDlg() : form(API::make_center(458, 170), appear::decorate<appear::minimize>())
{
	caption("Main-Menu");
	UnpackButton.create(*this, rectangle(20, 8, 406, 24));
	UnpackButton.caption("Unpack");
	UnpackButton.events().click(Unpack);
}


MainDlg::~MainDlg()
{
}


