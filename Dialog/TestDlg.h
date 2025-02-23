#pragma once
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>

void Box()
{
}

void TestDlg()
{
	using namespace nana;
	form fm(API::make_center(240, 160), appear::decorate<appear::minimize>());
	fm.caption("Menu");
	
	button btn(fm, rectangle(20, 20, 150, 30));
	btn.caption("Quit");
	btn.events().click(Box);
	fm.show();
	exec();
}